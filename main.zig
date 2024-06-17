const std = @import("std");
var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const allocator = gpa.allocator();
var buffered_reader = std.io.bufferedReader(std.io.getStdIn().reader());
const reader = buffered_reader.reader();
var buffered_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
const writer = buffered_writer.writer();
const Scanner = struct {
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
  const Self = @This();
  buffer: [1 << 20]u8 = undefined,
};

var scanner = Scanner.new();
const ArrayList = std.ArrayList;

pub fn main() !void {
  defer {
    if (gpa.deinit() == .leak) unreachable;
    buffered_writer.flush() catch unreachable;
  }
  var t: usize = 1;
  // t = try scanner.next(usize);
  while (t > 0) : (t -= 1) { try solve(); }
}

fn solve() !void {
  
}

fn suggestion1() !void {
  const arr = [_]i32 { 1, 2, 3, 4, 5 };

  // Currently, there are three ways to use the for loop.
  //
  for (0 .. 5) |i| { // 0, 1, 2, 3, 4
    try writer.print("{d} ", .{ i });
  }
  try writer.print("\n", .{});

  for (arr) |*e| { // 1, 2, 3, 4, 5
    try writer.print("{d} ", .{ e.* });
  }
  try writer.print("\n", .{});

  for (arr, 0 ..) |*e, i| { // 1, 2, 3, 4, 5 // 0, 1, 2, 3, 4
    try writer.print("{d} {d} ", .{ e.*, i });
  }
  try writer.print("\n", .{});

  // However, it doesn't provide a way to iterate in reverse order.
  // So, to repeat in reverse order, you must use a while statement.
  //
  var i: isize = arr.len - 1;
  while (i >= 0) : (i -= 1) {
    // ...
  }

  // Why not use this simple and modern methods of iterate with reverse.
  // This intuitively conveys to the programmer that the order is being
  // reversed.
  //
  for !(0 .. 5) |i| { // 4, 3, 2, 1, 0
    try writer.print("{d} ", .{ i });
  }
  try writer.print("\n", .{});

  for !(arr) |*e| { // 5, 4, 3, 2, 1
    try writer.print("{d} ", .{ e.* });
  }
  try writer.print("\n", .{});

  for !(arr, 0 ..) |*e, i| { // 5, 4, 3, 2, 1 // 4, 3, 2, 1, 0
    try writer.print("{d} {d} ", .{ e.*, i });
  }
  try writer.print("\n", .{});

  // Since it becomes clear when to use while statements and when to use for
  // statements, I think grammatical consistency can be improved.
  //
  const val: ?i32 = null;
  while (val) |v| {
    try writer.print("{d}\n", .{ v });
  } else {
    try writer.print("null\n", .{});
  }

  const a: i32 = l1: while (!std.ascii.isWhitespace('a')) {
    break :l1 10;
  } else {
    break :l1 20;
  };

  var tot: i32 = 0;
  for (0 .. 10) |i| {
    for !(i .. 10) |j| {
      for (i .. j + 1) |k| { tot += k; }
      for !(i .. j + 1) |k| { tot += k; }
    }
  }
  try writer.print("{d}\n". { tot });
}
