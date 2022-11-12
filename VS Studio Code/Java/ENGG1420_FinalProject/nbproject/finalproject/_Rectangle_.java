package finalproject;

import javafx.scene.paint.Color;
import javafx.scene.shape.Rectangle;

public class _Rectangle_ extends Shape {
    
    int length, width;
    int x, y;
    int border;
    Color color;
    Color borderColor;
    
    public _Rectangle_ (int length, int width, int x, int y, int border, Color color, Color borderColor) {
        
        this.length = length;
        this.width = width;
        this.x = x;
        this.y = y;
        this.border = border;
        this.color = color;
        this.borderColor = borderColor;
        
    }
    
    Rectangle create() {
        
        Rectangle output = new Rectangle(this.x, this.y, this.length, this.width);
        output.setStrokeWidth(this.border);
        output.setFill(this.color);
        output.setStroke(this.borderColor);
        
        return output;
        
    }
    
}
