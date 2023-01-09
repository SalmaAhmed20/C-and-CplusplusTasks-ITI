#ifndef GEOSHAPE_H
#define GEOSHAPE_H


class GeoShape
{
    public:
        GeoShape();

        int GetDim1() { return Dim1; }
        void SetDim1(int val) { Dim1 = val; }
        int GetDim2() { return Dim2; }
        void SetDim2(int val) { Dim2 = val; }

    protected:

    private:
        int Dim1;
        int Dim2;
};

#endif // GEOSHAPE_H
