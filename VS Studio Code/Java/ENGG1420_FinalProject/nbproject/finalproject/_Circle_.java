package finalproject;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

public class _Circle_ extends Shape {
    
    int r;
    int x, y;
    int border;
    Color color;
    Color borderColor;
    
    public _Circle_ (int r, int x, int y, int border, Color color, Color borderColor) {
        
        this.r = r;
        this.x = x;
        this.y = y;
        this.border = border;
        this.color = color;
        this.borderColor = borderColor;
    
    }
    
    Circle create() {
        
        Circle output = new Circle(this.x, this.y, this.r, this.color);
        output.setStrokeWidth(this.border);
        output.setStroke(this.borderColor);
        
        return output;
    }
    
}
