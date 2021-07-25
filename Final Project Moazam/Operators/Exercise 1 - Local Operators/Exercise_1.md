# OpenCV – Operators

## Done by : `Mohammad Moazam`

## Exercise 1 : Local operator

In this exercise we had to implement operators in our class.
We had to implement the following operators :

* Operator =
* Operator (i,j)
*Operator [index]

I was not sure to what to implement in the functions as it was explicitly mentioned in the exercise. So, I used them to implement Mat functions.

### `virtual void operator=(Mat& src)`

I used this operator to make a shallow copy of the given src.

### `virtual const Mat operator[](const Rect &roi)`

I used the [] to get the rect portion from the stored Mat object.

### `virtual const Vec3b operator()(int i, int j)`

I used to () to get the vector at location (i,j). (at(i,j) function of Mat)

___
