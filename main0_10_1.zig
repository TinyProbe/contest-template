// AtCoder Zig(version 0.10.1) template

const std = @import("std");
const Allocator = std.mem.Allocator;

var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const alloc = gpa.allocator();

pub fn main() !void {
  defer bufferedWriter.flush() catch unreachable;
  defer if (gpa.deinit()) unreachable;

  var t = Rng(usize).init(0, 1);
  // var t = Rng(usize).init(0, scan(usize));
  while (t.next()) |_| { try solve(); }
}

pub fn solve() !void {
}

var bufferedReader = std.io.bufferedReader(std.io.getStdIn().reader());
var bufferedWriter = std.io.bufferedWriter(std.io.getStdOut().writer());

fn readByte() ?u8 {
  const reader = bufferedReader.reader();
  const static = struct {
    var buf: [1 << 12]u8 = undefined;
    var len: usize = 0;
    var cur: usize = 0;
  };
  if (static.cur == static.len) {
    static.cur = 0;
    static.len = reader.read(static.buf[0 .. static.buf.len]) catch {
      @panic("readByte(): Error");
    };
    if (static.len == 0) { return null; }
  }
  defer static.cur += 1;
  return static.buf[static.cur];
}

pub fn scan(comptime T: type) T {
  const static = struct {
    var buf: [1 << 20]u8 = undefined;
    var cur: usize = undefined;
  };
  static.cur = 0;
  while (readByte()) |byte| {
    if (std.ascii.isWhitespace(byte)) { continue; }
    static.buf[static.cur] = byte;
    static.cur += 1;
    break;
  }
  while (readByte()) |byte| {
    if (std.ascii.isWhitespace(byte)) { break; }
    static.buf[static.cur] = byte;
    static.cur += 1;
  }
  return parseSlice(T, static.buf[0 .. static.cur]) catch {
    @panic("scan(): Error");
  };
}

pub fn print(comptime fmt: []const u8, args: anytype) void {
  const writer = bufferedWriter.writer();
  writer.print(fmt, args) catch @panic("print(): Error");
}

pub const Str = Vec(u8);

pub fn stringFrom(slice: []const u8) !Str {
  var str = Str.init(alloc);
  try str.assignSlice(slice);
  return str;
}

pub fn parse(comptime T: type, str: Str) !T {
  return parseSlice(T, str.items);
}

pub fn parseSlice(comptime T: type, slice: []const u8) !T {
  if (T == []const u8) {
    return slice;
  }
  return switch (@typeInfo(T)) {
    .Int => try std.fmt.parseInt(T, slice, 10),
    .Float => try std.fmt.parseFloat(T, slice),
    else => error.NotSupportedType,
  };
}

pub fn Rng(comptime T: type) type {
  return struct {
    left: T,
    right: T,

    const Self = @This();

    pub fn init(left: T, right: T) Self {
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

pub fn Vec(comptime T: type) type {
  return struct {
    items: []T,
    capacity: usize,
    allocator: Allocator,

    const Self = @This();
    const min_capacity: usize = 1 << 4;

    pub fn init(allocator: Allocator) Self {
      return .{
        .items = &[_]T {},
        .capacity = 0,
        .allocator = allocator,
      };
    }

    pub fn deinit(self: Self) void {
      if (@sizeOf(T) > 0) { self.allocator.free(self.allocatedSlice()); }
    }

    pub fn assign(self: *Self, obj: Self) Allocator.Error!void {
      try self.assignSlice(obj.items);
    }

    pub fn assignSlice(self: *Self, slice: []const T) Allocator.Error!void {
      if (isOverlaped(self.items, slice)) {
        std.mem.copy(T, self.items[0 .. slice.len], slice);
        try self.resize(slice.len);
      } else {
        try self.resize(slice.len);
        self.replaceSlice(0, slice);
      }
    }

    pub fn assignNTimes(
        self: *Self, n: usize, item: u8) Allocator.Error!void {
      try self.resize(n);
      self.replaceNTimes(0, n, item);
    }

    pub fn append(self: *Self, obj: Self) Allocator.Error!void {
      try self.appendSlice(obj.items);
    }

    pub fn appendSlice(self: *Self, slice: []const T) Allocator.Error!void {
      try self.resize(self.items.len + slice.len);
      self.replaceSlice(self.items.len - slice.len, slice);
    }

    pub fn appendNTimes(
        self: *Self, n: usize, item: u8) Allocator.Error!void {
      try self.resize(self.items.len + n);
      self.replaceNTimes(self.items.len - n, n, item);
    }

    pub fn insert(self: *Self, pos: usize, obj: Self) Allocator.Error!void {
      try self.insertSlice(pos, obj.items);
    }

    pub fn insertSlice(
        self: *Self,
        pos: usize, slice: []const T) Allocator.Error!void {
      self.resize(self.items.len + slice.len);
      std.mem.copyBackwards(
          T, self.items[pos + slice.len .. self.items.len],
          self.items[pos .. self.items.len - slice.len]);
      self.replaceSlice(pos, slice);
    }

    pub fn insertNTimes(
        self: *Self,
        pos: usize, n: usize, item: u8) Allocator.Error!void {
      try self.resize(self.items.len + n);
      std.mem.copyBackwards(
          T, self.items[pos + n .. self.items.len],
          self.items[pos .. self.items.len - n]);
      self.replaceNTimes(self.items.len - n, n, item);
    }

    pub fn replace(self: *Self, pos: usize, obj: Self) void {
      self.replaceSlice(pos, obj.items);
    }

    pub fn replaceSlice(self: *Self, pos: usize, slice: []const T) void {
      @memcpy(@ptrCast([*]u8, self.items.ptr + pos),
              @ptrCast([*]u8, slice.ptr), @sizeOf(T) * slice.len);
    }

    pub fn replaceNTimes(self: Self, pos: usize, n: usize, item: u8) void {
      @memset(@ptrCast([*]u8, self.items.ptr + pos),
              item, @sizeOf(T) * n);
    }

    pub fn find(self: Self, pos: usize, obj: Self) ?usize {
      return std.mem.indexOfPos(T, self.items, pos, obj.items);
    }

    pub fn findSlice(self: Self, pos: usize, slice: []const T) ?usize {
      return std.mem.indexOfPos(T, self.items, pos, slice);
    }

    pub fn findItem(self: Self, pos: usize, item: T) ?usize {
      return std.mem.indexOfScalarPos(T, self.items, pos, item);
    }

    pub fn findAny(self: Self, pos: usize, set: []const T) ?usize {
      return std.mem.indexOfAnyPos(T, self.items, pos, set);
    }

    pub fn findNone(self: Self, pos: usize, set: []const T) ?usize {
      return std.mem.indexOfNonePos(T, self.items, pos, set);
    }

    pub fn rfind(self: Self, obj: Self) ?usize {
      return std.mem.lastIndexOf(T, self.items, obj.items);
    }

    pub fn rfindSlice(self: Self, slice: []const T) ?usize {
      return std.mem.lastIndexOf(T, self.items, slice);
    }

    pub fn rfindItem(self: Self, item: T) ?usize {
      return std.mem.lastIndexOfScalar(T, self.items, item);
    }

    pub fn rfindAny(self: Self, set: []const T) ?usize {
      return std.mem.lastIndexOfAny(T, self.items, set);
    }

    pub fn rfindNone(self: Self, set: []const T) ?usize {
      return std.mem.lastIndexOfNone(T, self.items, set);
    }

    pub fn reverse(self: *Self) void {
      std.mem.reverse(T, self.items);
    }

    pub fn sort(self: *Self) void {
      std.mem.sort(T, self.items, {}, std.sort.asc(T));
    }

    pub fn clone(self: Self) Allocator.Error!Self {
      return self.cloneRange(self.items, 0, self.items.len);
    }

    pub fn cloneRange(
        self: Self, left: usize, right: usize) Allocator.Error!Self {
      var rtn = Self.init(self.allocator);
      try rtn.assignSlice(self.items[left .. right]);
      return rtn;
    }

    pub fn attach(self: Self, obj: Self) Allocator.Error!Self {
      var rtn = Self.init(self.allocator);
      try rtn.appendSlice(self.items);
      try rtn.appendSlice(obj.items);
      return rtn;
    }

    pub fn detach(self: Self, pos: usize) Allocator.Error![2]Self {
      var rtn1 = Self.init(self.allocator);
      var rtn2 = Self.init(self.allocator);
      try rtn1.appendSlice(self.items[0 .. pos]);
      try rtn2.appendSlice(self.items[pos .. self.items.len]);
      return .{ rtn1, rtn2 };
    }

    pub fn push(self: *Self, item: T) Allocator.Error!void {
      try self.resize(self.items.len + 1);
      self.items[self.items.len - 1] = item;
    }

    pub fn pop(self: *Self) Allocator.Error!?T {
      if (self.items.len == 0) { return null; }
      try self.resize(self.items.len - 1);
      return self.items.ptr[self.items.len];
    }

    pub fn swapPop(self: *Self, pos: usize) Allocator.Error!?T {
      std.mem.swap(T, &self.items[pos], &self.items[self.items.len - 1]);
      return try self.pop();
    }

    pub fn remove(self: *Self, pos: usize) Allocator.Error!void {
      try self.removeRange(pos, pos + 1);
    }

    pub fn removeRange(
        self: *Self, left: usize, right: usize) Allocator.Error!void {
      const width = right - left;
      std.mem.copy(
          T, self.items[left .. self.items.len - width],
          self.items[right .. self.items.len]);
      try self.resize(self.items.len - width);
    }

    pub fn resize(self: *Self, new_len: usize) Allocator.Error!void {
      if (self.capacity < new_len) {
        try self.realloc(optimizedCapacity(new_len));
      }
      self.items.len = new_len;
    }

    pub fn clear(self: *Self) Allocator.Error!void {
      try self.realloc(0);
      self.items.len = 0;
    }

    pub fn shrink(self: *Self) Allocator.Error!void {
      try self.realloc(self.items.len);
    }

    pub fn swap(self: *Self, obj: *Self) void {
      std.mem.swap(Self, self, obj);
    }

    pub fn at(self: Self, pos: usize) ?T {
      return if (pos < self.items.len) (self.items[pos]) else (null);
    }

    pub fn front(self: Self) ?T {
      return if (0 < self.items.len) (self.items[0]) else (null);
    }

    pub fn back(self: Self) ?T {
      return if (0 < self.items.len)
          (self.items[self.items.len - 1]) else (null);
    }

    pub fn begin(self: Self) [*]T {
      return @ptrCast(T, self.items);
    }

    pub fn end(self: Self) [*]T {
      return self.begin() + self.items.len;
    }

    pub fn iterRange(self: Self, left: usize, right: usize) Rng([*]T) {
      const ptr = self.begin();
      return Rng([*]T).init(ptr + left, ptr + right);
    }

    pub fn empty(self: Self) bool {
      return self.items.len == 0;
    }

    fn isOverlaped(lhs: []const T, rhs: []const T) bool {
      const lhs_l: usize = @ptrToInt(lhs.ptr);
      const lhs_r: usize = @ptrToInt(lhs.ptr + lhs.len);
      const rhs_l: usize = @ptrToInt(rhs.ptr);
      const rhs_r: usize = @ptrToInt(rhs.ptr + rhs.len);
      return if (lhs_r <= rhs_l or lhs_l >= rhs_r) (false) else (true);
    }

    fn optimizedCapacity(new_len: usize) usize {
      var max_bit: u6 = 0;
      if (new_len >> (max_bit + (1 << 4)) > 0) { max_bit |= (1 << 4); }
      if (new_len >> (max_bit + (1 << 3)) > 0) { max_bit |= (1 << 3); }
      if (new_len >> (max_bit + (1 << 2)) > 0) { max_bit |= (1 << 2); }
      if (new_len >> (max_bit + (1 << 1)) > 0) { max_bit |= (1 << 1); }
      if (new_len >> (max_bit + (1 << 0)) > 0) { max_bit |= (1 << 0); }
      return @max(@as(usize, 1) << (max_bit + 1), min_capacity);
    }

    fn allocatedSlice(self: Self) []T {
      return self.items.ptr[0 .. self.capacity];
    }

    fn realloc(self: *Self, new_capacity: usize) Allocator.Error!void {
      const old_memory = self.allocatedSlice();
      if (self.allocator.resize(old_memory, new_capacity)) |new_memory| {
        self.items.ptr = new_memory.ptr;
        self.capacity = new_memory.len;
      } else {
        const new_memory = try self.allocator.alloc(T, new_capacity);
        @memcpy(@ptrCast([*]u8, new_memory.ptr),
                @ptrCast([*]u8, self.items.ptr),
                @sizeOf(T) * self.items.len);
        self.allocator.free(old_memory);
        self.items.ptr = new_memory.ptr;
        self.capacity = new_memory.len;
      }
    }
  };
}
