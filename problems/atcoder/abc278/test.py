def confusing(h, m):
    h1 = h//10
    h2 = h%10
    m1 = m//10
    m2 = m%10
    return (h1*10+m1 < 24) and (h2*10 + m2 < 60)

l = []
all_confusing = []
for h in range(24):
    hl = []
    for m in range(60):
        if confusing(h, m):
            hl.append(m)
            all_confusing.append((h, m))
    l.append(hl)
for h, m in all_confusing:
    print(h, m)
