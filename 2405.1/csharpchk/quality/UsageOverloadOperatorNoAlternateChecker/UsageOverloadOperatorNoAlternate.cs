using System;

namespace UsageLibrary
{
    public struct Point
    {
        private int x,y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return String.Format("({0},{1})",x,y);
        }

        // Violates rule: OperatorOverloadsHaveNamedAlternates.
        public static Point operator+(Point a, Point b) // @violation
        {
            return new Point(a.x + b.x, a.y + b.y);
        }

        public int X {get {return x;}}
        public int Y {get {return x;}}
    }

    public struct PointOverload
    {
        private int x,y;

        public Point(int x, int y)
        {
            this.x = x;
            this.y = y;
        }

        public override string ToString()
        {
            return String.Format("({0},{1})",x,y);
        }

        public static Point operator+(Point a, Point b) // @safe
        {
            return new Point(a.x + b.x, a.y + b.y);
        }

        public Point Add(Point a, Point b) {
            return new Point(a.x + b.x, a.y + b.y);
        }

        public int X {get {return x;}}
        public int Y {get {return x;}}
    }
}