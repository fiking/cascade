localparam x = 1;
localparam y = 1;

initial begin
  $write(+x);
  $write(x+y);
  $finish;
end
