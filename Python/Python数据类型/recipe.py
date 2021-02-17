# coding=utf8
# print recipe accroding to given width

recipe_width = int(input("PLease enter width of the recipe:"))

price_width = 10
item_width = recipe_width - price_width

header_format = "{{:<{}}}{{:>{}}}".format(item_width, price_width)
content_format = "{{:{}}}{{:>{}.2f}}".format(item_width, price_width)
#注意到，这里实际上是分两次格式化字符串
#item_width和price_width替换最内层的花括号，最外层的花括号格式化后被去掉
#因此最后只剩下中间一层的花括号

print('=' * recipe_width)

print(header_format.format('Item', 'Price'))

print('-' * recipe_width)

print(content_format.format('Apple', 0.4))
print(content_format.format('Banana', 0.5))
print(content_format.format('Steak', 9.9))
print(content_format.format('Chicken', 7.2))
print(content_format.format('Cookie', 2.0))
print(content_format.format('Bread', 0.8))
print(content_format.format('Icecream', 1.5))
print(content_format.format('Cola', 0.5))

print('=' * recipe_width)
