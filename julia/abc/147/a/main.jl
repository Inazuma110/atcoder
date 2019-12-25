function main()
  a1, a2, a3 = parse.(Int, split(readline()))
  if a1 + a2 + a3 >= 22
    println("bust")
  else
    println("win")
  end
end

main()
