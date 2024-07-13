const std = @import("std");
var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const allocator = gpa.allocator();

var buffered_reader = std.io.bufferedReader(std.io.getStdIn().reader());
const reader = buffered_reader.reader();
var buffered_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
const writer = buffered_writer.writer();

var scanner = Scanner.new();

const Scanner = struct {
  const Self = @This();
  buffer: [1 << 20]u8 = undefined,

  fn new() Self {
    return Self {};
  }
  fn nextItem(self: *Self) ![]const u8 {
    var byte: u8 = try reader.readByte();
    while (std.ascii.isWhitespace(byte)) {
      byte = try reader.readByte();
    }
    for (0 .. self.buffer.len) |i| {
      self.buffer[i] = byte;
      byte = try reader.readByte();
      if (std.ascii.isWhitespace(byte)) {
        return self.buffer[0 .. i + 1];
      }
    }
    return self.buffer[0 .. self.buffer.len];
  }
  fn next(self: *Self, comptime T: type) !T {
    switch (@typeInfo(T)) {
      .Int => return try std.fmt.parseInt(T, try self.nextItem(), 10),
      .Float => return try std.fmt.parseFloat(T, try self.nextItem()),
      .Struct => {
        var arrlist = T.init(allocator);
        try arrlist.appendSlice(try self.nextItem());
        return arrlist;
      },
      else => return error { NotSupportType }.NotSupportType,
    }
  }
};

pub fn main() !void {
  defer {
    if (gpa.deinit() == .leak) unreachable;
    buffered_writer.flush() catch unreachable;
  }
  var t: usize = 1;
  // t = try scanner.next(usize);
  while (t > 0) : (t -= 1) {
    try solve();
  }
}

fn solve() !void {
  try writer.print("hello, world!\n", .{});
}
