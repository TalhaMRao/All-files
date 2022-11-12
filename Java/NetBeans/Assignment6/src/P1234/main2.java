package P1234;

/**
 * @author talha
 * P4
 * due Monday 8 am
 */
public class main2
{
    public static void main(String[] args)
    {
        Circle[] circle;//new circle
        circle = new Circle[100];//makes size of the circle array 100
        
        Circle circle2 = new Circle();//new circle
        circle2.radius = 120;//sets its radius to 120
        circle = circle2.decompose(0);//calls method that dosent work :(
    }
}
