class Sphere {
    private:
        double radius;
        char color;
    public:
        Sphere();
        Sphere(double, char = '?');

        double getRadius() const;
        char getColor() const;
        double getDiameter() const;
        double getSurfaceArea() const;
        double getVolume() const;

        void setRadius(double);
        void setColor(char);
        void grow(double);
        void shrink(double);
        void randomizeColor();

        void printSummary(int = 2) const;
};