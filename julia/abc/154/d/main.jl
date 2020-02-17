n = parse(Int, readline())
v = parse.(Int, split(readline(), ' '))

d = Dict()
for i in v
  d[i] = get(d, i, 0) + 1
  if d[i] == 2
    println("NO")
    exit(0)
  end
end
println("YES")

