def beautySum(str):
    d = {}
    i = 1
    while(len(str)):
        ch = str[i-1]
        if ch not in d.keys():
            d[ch] = 1
        else:
            d[ch] += 1

    dic = sorted(d.items(), key = lambda x:x[1], reverse=True)
    converted_dic = dict(dic)
    freq = list(converted_dic.values())
    return freq[0] - freq[-1]

print(beautySum("abaacc"))


