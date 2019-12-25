a, b = parse.(Int, split(readline()))
if a >= 10 || b >= 10
  println(-1)
else
  println(a * b)
end
