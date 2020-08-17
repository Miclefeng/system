
function maxinum(a)
    local mi = 1
    local m = a[mi]
    for i,val in ipairs(a) do
        if val > m then
            mi = i; m = val 
        end
    end
    return m,mi
end

print(maxinum({3,9,20,13,6}))
