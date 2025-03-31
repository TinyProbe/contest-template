const std = @import("std");

pub fn main() !void {
  defer {
    if (gpa.deinit() == .leak) unreachable;
    // if (gpa.deinit()) unreachable;
    buffered_writer.flush() catch unreachable;
  }
  try Scanner.scanInput();
  var t = Rng(usize, 0, 1);
  // var t = Rng(usize, 0, scan(usize));
  while (t.next()) |_| { try solve(); }
}

fn solve() !void {
  print("Hello, World!\n", .{});
}

var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const allocator = gpa.allocator();
var buffered_reader = std.io.bufferedReader(std.io.getStdIn().reader());
var buffered_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
const reader = buffered_reader.reader();
const writer = buffered_writer.writer();

pub fn scan(comptime T: type) T {
  return Scanner.next(T) catch unreachable;
}
pub fn print(comptime format: []const u8, args: anytype) void {
  writer.print(format, args) catch unreachable;
}

const Scanner = struct {
  var buf: [1 << 24]u8 = undefined;
  var len: usize = undefined;
  var cur: usize = 0;

  pub fn scanInput() !void { len = try reader.read(buf[0 .. ]); }
  fn nextItem() []const u8 {
    while (cur < len and std.ascii.isWhitespace(buf[cur])) { cur += 1; }
    const l = cur;
    while (cur < len and !std.ascii.isWhitespace(buf[cur])) { cur += 1; }
    return buf[l .. cur];
  }
  pub fn next(comptime T: type) !T {
    const info = @typeInfo(T);
    return switch (info) {
      .int => try std.fmt.parseInt(T, nextItem(), 10),
      .float => try std.fmt.parseFloat(T, nextItem()),
      .pointer => if (info.pointer.child == u8) (nextItem()) else (error.NotSupportedType),
      else => error.NotSupportedType,
    };
  }
};

pub fn Rng(comptime T: type, beg: T, end: T) _Rng(T) {
  return .{ .asc = beg < end, .beg = beg, .end = end };
}
fn _Rng(comptime T: type) type {
  return struct {
    asc: bool,
    beg: T,
    end: T,

    pub fn next(self: *@This()) ?T {
      if (self.beg == self.end) { return null; }
      if (self.asc) {
        defer self.beg += 1;
        return self.beg;
      } else {
        defer self.beg -= 1;
        return self.beg - 1;
      }
    }
  };
}
