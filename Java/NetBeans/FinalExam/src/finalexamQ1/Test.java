package finalexamQ1;

/**
 * @author Talha Rao 1088904 Final Exam Thursday April 21, 2022
 */
public class Test
{

    public static void main(String[] args)
    {
        Shape[] shapes = new Shape[4];
        shapes[0] = new Circle(2, 5);
        shapes[1] = new Circle(3, 6);
        shapes[2] = new Rectangle(1, 2, 4);
        shapes[3] = new Rectangle(3, 4, 5);

        Utils.zoom(shapes);

    }

}
