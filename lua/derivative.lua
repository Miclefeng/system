function deriva(f,delta)
    delta = delta or 1e-4
    return function (x)
        return (f(x + delta) - f(x)) / delta
    end
end

c = deriva(math.sin)
print(math.cos(10),c(10))
