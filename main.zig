const std = @import("std");
const stdc = @cImport(@cInclude("string.h")); // need -lc
const Allocator = std.mem.Allocator;

var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const alloc = gpa.allocator();

pub fn main() !void {
  defer if (gpa.deinit() == .leak) unreachable;
  var t = Rng(usize).init(0, 1);
  // var t = Rng(usize).init(0, scan(usize));
  while (t.next()) |_| { try solve(); }
}

pub fn solve() !void {
  var s = scan(Str); defer s.deinit();
  var a = Vec(i32).init(alloc); defer a.deinit();
  var rg = Rng(i32).init(1, 11);
  while (rg.prev()) |i| { try a.push(i); }
  print("{any}\n", .{ a.data() });
}

fn readByte() ?u8 {
  const reader = std.io.getStdIn().reader();
  const static = struct {
    const bufLen = 1 << 12;
    var buf: [bufLen]u8 = undefined;
    var len: usize = 0;
    var cur: usize = 0;
  };
  if (static.cur == static.len) {
    static.cur = 0;
    static.len = reader.read(static.buf[0 .. static.buf.len]) catch {
      @panic("readByte(): Error");
    };
    if (static.cur == static.len) { return null; }
  }
  defer static.cur += 1;
  return static.buf[static.cur];
}

pub fn scan(comptime T: type) T {
  var s = Str.init(alloc);
  while (readByte()) |byte| {
    if (!std.ascii.isWhitespace(byte)) {
      s.push(byte) catch @panic("scan(): s.push(byte): Error");
      break;
    }
  }
  while (readByte()) |byte| {
    if (std.ascii.isWhitespace(byte)) { break; }
    s.push(byte) catch @panic("scan(): s.push(byte): Error");
  }
  if (T == Str) { return s; }
  defer s.deinit();
  return parse(T, &s) catch @panic("scan(): parse(T, &s): Error");
}

pub fn print(comptime fmt: []const u8, args: anytype) void {
  const writer = std.io.getStdOut().writer();
  writer.print(fmt, args) catch @panic("print(): Error");
}

pub fn Vec(comptime T: type) type {
  return struct {
    arrayList: std.ArrayList(T),

    pub const Self = @This();

    pub fn init(allocator: Allocator) Self {
      return .{ .arrayList = std.ArrayList(T).init(allocator) };
    }

    pub fn deinit(self: Self) void {
      self.arrayList.deinit();
    }

    pub fn assign(self: *Self, obj: *const Self) Allocator.Error!void {
      if (self == obj) { return; }
      try self.arrayList.resize(0);
      try self.arrayList.appendSlice(obj.arrayList.items);
    }

    pub fn assignSlice(self: *Self, slice: []const T) Allocator.Error!void {
      const items = self.arrayList.items;
      const self_l: usize = @intFromPtr(items.ptr);
      const self_r: usize = @intFromPtr(items.ptr + items.len);
      const slice_l: usize = @intFromPtr(slice.ptr);
      const slice_r: usize = @intFromPtr(slice.ptr + slice.len);
      if (self_r <= slice_l or self_l >= slice_r) {
        try self.arrayList.resize(0);
        try self.arrayList.appendSlice(slice);
      } else {
        std.mem.copyForwards(T, items[0 .. slice.len], slice);
        try self.arrayList.resize(slice.len);
      }
    }

    pub fn assignNTimes(self: *Self, n: usize, item: T) Allocator.Error!void {
      try self.arrayList.resize(0);
      try self.arrayList.appendNTimes(item, n);
    }

    pub fn append(self: *Self, obj: *const Self) Allocator.Error!void {
      try self.arrayList.appendSlice(obj.arrayList.items);
    }

    pub fn appendSlice(self: *Self, slice: []const T) Allocator.Error!void {
      try self.arrayList.appendSlice(slice);
    }

    pub fn appendNTimes(self: *Self, n: usize, item: T) Allocator.Error!void {
      try self.arrayList.appendNTimes(item, n);
    }

    pub fn insert(self: *Self,
                  pos: usize, obj: *const Self) Allocator.Error!void {
      if (self == obj) {
        const n = self.arrayList.items.len;
        try self.arrayList.resize(n + n);
        const items = self.arrayList.items;
        std.mem.copyBackwards(
            T, items[pos + n .. items.len], items[pos .. items.len - n]);
        @memcpy(items[pos .. pos + pos], items[0 .. pos]);
        @memcpy(items[pos + pos .. pos + n], items[pos + n .. items.len]);
      } else {
        try self.arrayList.insertSlice(pos, obj.arrayList.items);
      }
    }

    // need refactorying
    pub fn insertSlice(self: *Self,
                       pos: usize, slice: []const T) Allocator.Error!void {
      var items = self.arrayList.items;
      const self_l: usize = @intFromPtr(items.ptr);
      const self_r: usize = @intFromPtr(items.ptr + items.len);
      const pos_l: usize = @intFromPtr(items.ptr + pos);
      const slice_l: usize = @intFromPtr(slice.ptr);
      const slice_r: usize = @intFromPtr(slice.ptr + slice.len);
      if (self_r <= slice_l or self_l >= slice_r or pos_l >= slice_r) {
        try self.arrayList.insertSlice(pos, slice);
      } else {
        const n = slice.len;
        const posi_r = pos + n;
        try self.arrayList.resize(items.len + n);
        items = self.arrayList.items;
        std.mem.copyBackwards(
            T, items[posi_r .. items.len], items[pos .. items.len - n]);
        if (pos_l > slice_l) {
          const slicei_l = slice.ptr - items.ptr;
          const l_len = pos - slicei_l;
          const r_len = n - l_len;
          @memcpy(items[pos .. pos + l_len], items[slicei_l .. pos]);
          @memcpy(items[pos + l_len .. posi_r],
                  items[posi_r .. posi_r + r_len]);
        } else {
          const slicei_l = slice.ptr - items.ptr + n;
          @memcpy(items[pos .. posi_r], items[slicei_l .. slicei_l + n]);
        }
      }
    }

    pub fn insertNTimes(self: *Self,
                        pos: usize, n: usize, item: T) Allocator.Error!void {
      try self.arrayList.resize(self.arrayList.items.len + n);
      const items = self.arrayList.items;
      std.mem.copyBackwards(
          T, items[pos + n .. items.len], items[pos .. items.len - n]);
      @memset(items[pos .. pos + n], item);
    }

    pub fn replace(self: *Self, pos: usize, obj: *const Self) void {
      const items = obj.arrayList.items;
      self.arrayList.replaceRange(pos, items.len, items) catch {
        @panic("replace(): OutOfMemory");
      };
    }

    pub fn replaceSlice(self: *Self, pos: usize, slice: []const T) void {
      self.arrayList.replaceRange(pos, slice.len, slice) catch {
        @panic("replaceSlice(): OutOfMemory");
      };
    }

    pub fn replaceNTimes(self: *Self, pos: usize, n: usize, item: T) void {
      @memset(self.arrayList.items[pos .. pos + n], item);
    }

    pub fn find(self: *const Self, pos: usize, obj: *const Self) ?usize {
      return std.mem.indexOfPos(
          T, self.arrayList.items, pos, obj.arrayList.items);
    }

    pub fn findSlice(self: *const Self, pos: usize, slice: []const T) ?usize {
      return std.mem.indexOfPos(T, self.arrayList.items, pos, slice);
    }

    pub fn findItem(self: *const Self, pos: usize, item: T) ?usize {
      return std.mem.indexOfScalarPos(T, self.arrayList.items, pos, item);
    }

    pub fn findAny(self: *const Self, pos: usize, set: []const T) ?usize {
      return std.mem.indexOfAnyPos(T, self.arrayList.items, pos, set);
    }

    pub fn findNone(self: *const Self, pos: usize, set: []const T) ?usize {
      return std.mem.indexOfNonePos(T, self.arrayList.items, pos, set);
    }

    pub fn rfind(self: *const Self, obj: *const Self) ?usize {
      return std.mem.lastIndexOf(
          T, self.arrayList.items, obj.arrayList.items);
    }

    pub fn rfindSlice(self: *const Self, slice: []const T) ?usize {
      return std.mem.lastIndexOf(T, self.arrayList.items, slice);
    }

    pub fn rfindItem(self: *const Self, item: T) ?usize {
      return std.mem.lastIndexOfScalar(T, self.arrayList.items, item);
    }

    pub fn rfindAny(self: *const Self, set: []const T) ?usize {
      return std.mem.lastIndexOfAny(T, self.arrayList.items, set);
    }

    pub fn rfindNone(self: *const Self, set: []const T) ?usize {
      return std.mem.lastIndexOfNone(T, self.arrayList.items, set);
    }

    pub fn reverse(self: *Self) void {
      std.mem.reverse(T, self.arrayList.items);
    }

    pub fn sort(self: *Self) void {
      std.mem.sort(T, self.arrayList.items, {}, std.sort.asc(T));
    }

    pub fn clone(self: *const Self) Allocator.Error!Self {
      return .{ .arrayList = try self.arrayList.clone() };
    }

    pub fn cloneRange(self: *const Self,
                      left: usize, right: usize) Allocator.Error!Self {
      var rtn = Self {
        .arrayList = std.ArrayList(T).init(self.arrayList.allocator) };
      try rtn.arrayList.appendSlice(self.arrayList.items[left .. right]);
      return rtn;
    }

    pub fn attach(self: *const Self, obj: *const Self) Allocator.Error!Self {
      var rtn = Self {
        .arrayList = std.ArrayList(T).init(self.arrayList.allocator) };
      try rtn.arrayList.appendSlice(self.arrayList.items);
      try rtn.arrayList.appendSlice(obj.arrayList.items);
      return rtn;
    }

    pub fn detach(self: *const Self, pos: usize) Allocator.Error![2]Self {
      var rtn = [2]Self {
        .{ .arrayList = std.ArrayList(T).init(self.arrayList.allocator) },
        .{ .arrayList = std.ArrayList(T).init(self.arrayList.allocator) },
      };
      const items = self.arrayList.items;
      try rtn[0].arrayList.appendSlice(items[0 .. pos]);
      try rtn[1].arrayList.appendSlice(items[pos .. items.len]);
      return rtn;
    }

    pub fn copy(self: *const Self,
                target: []T, left: usize, right: usize) void {
      @memcpy(target, self.arrayList.items[left .. right]);
    }

    pub fn push(self: *Self, item: T) Allocator.Error!void {
      try self.arrayList.append(item);
    }

    pub fn pop(self: *Self) ?T {
      return self.arrayList.pop();
    }

    pub fn swapPop(self: *Self, pos: usize) ?T {
      return
          if (pos < self.arrayList.items.len) (self.arrayList.swapRemove(pos))
          else (null);
    }

    pub fn remove(self: *Self, pos: usize) T {
      return self.arrayList.orderedRemove(pos);
    }

    pub fn removeRange(self: *Self, left: usize, right: usize) void {
      const items = self.arrayList.items;
      const dist = right - left;
      std.mem.copyForwards(
          T, items[left .. items.len - dist], items[right .. items.len]);
      self.arrayList.resize(items.len - dist) catch unreachable;
    }

    pub fn resize(self: *Self, count: usize) Allocator.Error!void {
      self.arrayList.resize(count);
    }

    pub fn clear(self: *Self) void {
      self.arrayList.clearAndFree();
    }

    pub fn shrink(self: *Self) void {
      self.arrayList.shrinkAndFree();
    }

    pub fn swap(self: *Self, obj: *Self) void {
      std.mem.swap(Self, self, obj);
    }

    pub fn data(self: *const Self) []T {
      return self.arrayList.items;
    }

    pub fn at(self: *const Self, pos: usize) ?T {
      const items = self.arrayList.items;
      return if (pos < items.len) (items[pos]) else (null);
    }

    pub fn front(self: *const Self) ?T {
      const items = self.arrayList.items;
      return if (0 < items.len) (items[0]) else (null);
    }

    pub fn back(self: *const Self) ?T {
      const items = self.arrayList.items;
      return if (0 < items.len) (items[items.len - 1]) else (null);
    }

    pub fn begin(self: *const Self) [*]T {
      return @ptrCast(self.arrayList.items);
    }

    pub fn end(self: *const Self) [*]T {
      const ptr: [*]T = @ptrCast(self.arrayList.items);
      return ptr + self.arrayList.items.len;
    }

    pub fn iterRange(self: *const Self, left: usize, right: usize) Rng([*]T) {
      const ptr: [*]T = @ptrCast(self.arrayList.items);
      return Rng([*]T).init(ptr + left, ptr + right);
    }

    pub fn empty(self: *const Self) bool {
      return self.arrayList.items.len == 0;
    }

    pub fn size(self: *const Self) usize {
      return self.arrayList.items.len;
    }

    pub fn length(self: *const Self) usize {
      return self.arrayList.items.len;
    }

    pub fn capacity(self: *const Self) usize {
      return self.arrayList.capacity;
    }
  };
}

pub const Str = Vec(u8);

pub fn compare(lhs: *const Str, rhs: *const Str) i32 {
  return compareSlice(lhs.data(), rhs.data());
}

pub fn compareRange(lhs: Rng([*]u8), rhs: Rng([*]u8)) i32 {
  return compareSlice(lhs.left[0 .. lhs.right - lhs.left],
                      rhs.left[0 .. rhs.right - rhs.left]);
}

pub fn compareSlice(lhs: []const u8, rhs: []const u8) i32 {
  return @intCast(stdc.strcmp(@ptrCast(lhs), @ptrCast(rhs)));
}

pub fn parse(comptime T: type, str: *const Str) !T {
  return parseSlice(T, str.data());
}

pub fn parseSlice(comptime T: type, slice: []const u8) !T {
  return switch (@typeInfo(T)) {
    .int => try std.fmt.parseInt(T, slice, 10),
    .float => try std.fmt.parseFloat(T, slice),
    else => error.NotSupportedType,
  };
}

pub fn Rng(comptime T: type) type {
  return struct {
    left: T,
    right: T,

    pub const Self = @This();

    pub fn init(left: T, right: T) Self {
      if (@typeInfo(T) == .pointer) {
        const l: usize = @intFromPtr(left);
        const r: usize = @intFromPtr(right);
        if (l > r) { @panic("Rng(T).init(): left > right"); }
      } else if (left > right) {
        @panic("Rng(T).init(): left > right");
      }
      return .{ .left = left, .right = right };
    }

    pub fn next(self: *Self) ?T {
      if (self.left == self.right) { return null; }
      defer self.left += 1;
      return self.left;
    }

    pub fn prev(self: *Self) ?T {
      if (self.left == self.right) { return null; }
      defer self.right -= 1;
      return self.right - 1;
    }
  };
}
