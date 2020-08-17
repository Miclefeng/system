require("print_r")
table.print = print_r
network = {{name="grauna",IP="210.26.30.34"},{name="arraial",IP="210.26.30.23"},{name="lua",IP="210.26.30.12"},{name="derain",IP="210.26.30.20"}}

table.sort(network,function(a,b) return (a.name < b.name ) end)

table.print(network)
