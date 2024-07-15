const std = @import("std");
var gpa = std.heap.GeneralPurposeAllocator(.{}) {};
const allocator = gpa.allocator();

var buffered_reader = std.io.bufferedReader(std.io.getStdIn().reader());
var buffered_writer = std.io.bufferedWriter(std.io.getStdOut().writer());
const reader = buffered_reader.reader();
const writer = buffered_writer.writer();

const Scanner = struct {
  var buffer: [1 << 22]u8 = undefined; // wanning: string cutting.
  var len: usize = 0;
  var cur: usize = 0;

  fn nextItem() ![]const u8 {
    if (cur == len) {
      len = try reader.readAll(&buffer);
      cur = 0;
    }
    while (cur < len and std.ascii.isWhitespace(buffer[cur])) { cur += 1; }
    const l = cur;
    while (cur < len and !std.ascii.isWhitespace(buffer[cur])) { cur += 1; }
    return buffer[l .. cur];
  }
  fn next(comptime T: type) !T {
    switch (@typeInfo(T)) {
      .Int => return try std.fmt.parseInt(T, try nextItem(), 10),
      .Float => return try std.fmt.parseFloat(T, try nextItem()),
      .Struct => {
        var arrlst = T.init(allocator);
        try arrlst.appendSlice(try nextItem());
        return arrlst;
      },
      else => return error { NotSupportType }.NotSupportType,
    }
  }
};

pub fn main() !void {
  defer {
    // if (gpa.deinit() == .leak) unreachable;
    if (gpa.deinit()) unreachable;
    buffered_writer.flush() catch unreachable;
  }
  var t: usize = 1;
  // t = try Scanner.next(usize);
  while (t > 0) : (t -= 1) { try solve(); }
}

fn solve() !void {
}
