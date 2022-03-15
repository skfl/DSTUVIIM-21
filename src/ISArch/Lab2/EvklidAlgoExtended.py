def euclid_algo_ext(p, mod):
    start = mod
    x = 1
    xi = 0
    y = 0
    yi = 1
    while mod > 0:
        q = p // mod
        p, mod = mod, p % mod
        x, xi = xi, x - xi * q
        y, yi = yi, y - yi * q
    if (x < 0):
        return start + x + 1
    return (x)


print("P^-1 = :")
print(euclid_algo_ext(17, 73), " для чисел 17 и 73")
print(euclid_algo_ext(37, 141), " для чисел 37 и 141")
print(euclid_algo_ext(53, 37), " для чисел 53 и 37")
print(euclid_algo_ext(14, 19), " для чисел 14 и 19")
print(euclid_algo_ext(23, 30), " для чисел 23 и 30")
print(euclid_algo_ext(35, 23), " для чисел 25 и 23")
