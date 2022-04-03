mymap = { 1: "a", 1 : "b" }
print(mymap[1])
for key in mymap :
    print(key, '=', mymap[key])
for key, value in mymap.items() :
    print(key, '=', value)


dic = {'a': 4}
dic['jack'] = 3
print(dic.get('not', False))

print('jack' in dic)
del dic['jack']
print('jack' in dic)


