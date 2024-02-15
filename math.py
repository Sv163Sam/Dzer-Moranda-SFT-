import scipy.interpolate as interpolate
import scipy.optimize as optimize
def func(x, a, b):
    return a * x + b

def mnk(x, y):
  X = np.column_stack((x, np.ones(len(x))))
  XTX = np.dot(X.T, X)
  XTX_inv = np.linalg.inv(XTX)
  XTy = np.dot(X.T, y)
  a, b = np.dot(XTX_inv, XTy)
  return a, b


#y = data нужно делать на рандомном массиве
y = [ 4, 4, 2, 2, 1, 1, 1 ]#[1, 2, 4, 0, 4, 4, 3, 3, 2, 4]#
x = np.arange(len(y))
nevaz = []
nevaz_2 = []
for i in range(len(y)):
  nevaz.append(y[i] - delta_nj[i])
  nevaz_2.append((y[i] - delta_nj[i])**2)
params = mnk(x, y)
print("a, b = ", params[0], params[1])
print("Sum_nevaz: ", np.sum(nevaz))
new_y = func(x, params[0], params[1])
plt.plot(x, y)
plt.plot(x, new_y)
plt.plot(x, nevaz, 'o') # невязки (точки)
plt.plot(x, nevaz_2, 'o') # квадраты невязок (точки)
