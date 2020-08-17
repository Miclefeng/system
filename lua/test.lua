
local x = 10
if true then 
    local x = x + 1
    print(x)
    do
        local x = x + 1
        print(x)
    end
    print(x)
end
print(x)
