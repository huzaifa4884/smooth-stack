interface Shape {
    
    double calculateArea();
    void display();
}


class Racatangle implements Shape {

    private double length;
    private double width;

    public Racatangle(double length , double width) {
        this.length = length;
        this.width = width;
    }

    @Override
    public double calculateArea() {
        
        return length * width;
    }

    @Override
    public void display() {
        
        System.out.println("Rectangle");
    }
    
}

class Triangle implements Shape {
    
    private double side1;
    private double side2;
    
    public Triangle(double side1 , double side2) {
        this.side1 = side1;
        this.side2 = side2;
    }

    @Override
    public double calculateArea() {
        
        return side1 * side2 / 2 ;
    }

    @Override
    public void display() {
        
        System.out.println("Triangle");
        
    }
    
}

class Circle implements Shape {

    private double radius;

    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double calculateArea() {
        
        return 3.14 * radius * radius;
    }

    @Override
    public void display() {
        System.out.println("Circle");
        
    }
    
}

public class Ass3 {
    public static void main(String args[]){

        Racatangle rect = new Racatangle(4, 5);
        System.out.println(rect.calculateArea());
        rect.display();

        System.out.println("next shape");

        Triangle tri = new Triangle(2, 3);
        System.out.println(tri.calculateArea());
        tri.display();

        System.out.println("next shape");

        Circle cir = new Circle(4);
        System.out.println(cir.calculateArea());
        cir.display();

    }
}
