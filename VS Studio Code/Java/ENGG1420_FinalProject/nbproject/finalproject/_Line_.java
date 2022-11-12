package finalproject;

import javafx.scene.paint.Color;
import javafx.scene.shape.Line;

public class _Line_ extends Shape {
    
    int startX, startY;
    int endX, endY;
    int border;
    Color color;
    
    public _Line_ (int startX, int startY, int endX, int endY, int border, Color color) {
        
        this.startX = startX;
        this.startY = startY;
        this.endX = endX;
        this.endY = endY;
        this.border = border;
        this.color = color;
        
    }
    
    Line create() {
        
        Line output = new Line(this.startX, this.startY, this.endX, this.endY);
        output.setStrokeWidth(this.border);
        output.setStroke(this.color);
        
        return output;
        
    }
    
}
