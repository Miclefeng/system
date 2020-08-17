
function add (a)
    local sum = 0
    for i,v in pairs(a) do
        sum = sum + v
    end
    return sum
end

a = {sunday=1,monday=2,tuesday=3,wendnesday=4,thursday=5,friday=6,saturday=7}

local sum = 0
for i,v in pairs(a) do
    sum = sum + v
end
print(sum)
print(add(a))
