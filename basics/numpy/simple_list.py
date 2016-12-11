xs = [1, 2, 3] 
for x in xs: print x
xs.append('numpy')
print xs[-1]
x = xs.pop()
print x

nums = range(5)
for num in nums: 
   print num
print nums[2:4]
print nums[:2]
print nums[2:]
print nums[:]

squares = [x * 2 for x in nums]
print squares
