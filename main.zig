const std = @import("std");
const string_h = @cImport(@cInclude("string.h")); // need -lc

pub fn main() !void {
  defer bufferedWriter.flush() catch unreachable;
  // var t = Rng(usize).init(0, 1);
  var t = Rng(usize).init(0, scan(usize));
  while (t.next()) |_| { try solve(); }
}

pub fn solve() !void {
  print("{d}\n", .{scan(usize)});
}

var bufferedReader = std.io.BufferedReader(std.io.getStdIn().reader());
var bufferedWriter = std.io.BufferedWriter(std.io.getStdOut().writer());

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

pub fn compareSlice(lhs: []const u8, rhs: []const u8) i32 {
  return @intCast(string_h.strcmp(@ptrCast(lhs), @ptrCast(rhs)));
}

pub fn parseSlice(comptime T: type, slice: []const u8) !T {
  if (T == []const u8) { return slice; }
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
      switch (@typeInfo(T)) {
        .pointer =>
            if (@as(usize, @intFromPtr(left)) > @as(usize, @intFromPtr(right)))
              @panic("Rng(T).init(): left > right"),
        .int => if (left > right) @panic("Rng(T).init(): left > right"),
        else => @panic("Rng(T).init(): NotSupportedType"),
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
