# OpenCV – Operators

## Done by : `Mohammad Moazam`

## Exercise 2 : Global operator

In this exercise we were asked to define ``<< , >> operators`` globally.

### `>> Operator`

    Mat& operator>>(Mat& src, Base& baseObj) {
        baseObj.compute(src);
        return src;
    }

As in the code compute is a virtual function and I using the *>> operator* to compute the process and forward the base object that can be further used as Mat.

### `<< Operator`

    ostream& operator<<(std::ostream& outStream, Base& imageProcessing) {

        outStream << imageProcessing.getOpenCVProcessName() << endl;

        return outStream;

    }

I used the out stream, so that we directly print the process name using cout as asked in the exercise.

___

### Comments

I have transferred all the global functions and constants inside `psrs/base.h` file.
