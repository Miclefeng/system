require('print_r')
names = {"Peter","Paul","Mary"}
grades = {Mary=10,Paul=7,Peter=8}

function sortbygrade (names,grades)
    table.sort(names,function(n1,n2) return  grades[n1] < grades[n2] end)
end

sortbygrade(names,grades)
print_r(names)
    
