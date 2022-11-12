package finalproject;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.shape.Line;
import javafx.scene.shape.Rectangle;
import javafx.stage.Stage;


public class AnimationPlayer extends Application {
    
    @Override
    public void start(Stage primaryStage) {
        
        _Circle_ circle = new _Circle_ (100, 200, 200, 5, Color.RED, Color.DARKRED);
        Circle test1 = circle.create();
        
        _Rectangle_ rectangle = new _Rectangle_ (300, 100, 600, 200, 5, Color.BLUE, Color.DARKBLUE);
        Rectangle test2 = rectangle.create();
        
        _Line_ line = new _Line_ (200, 400, 800, 800, 5, Color.GREEN);
        Line test3 = line.create();
        
        Pane pane = new Pane();
        pane.getChildren().add(test1);
        pane.getChildren().add(test2);
        pane.getChildren().add(test3);
        
        Scene scene = new Scene(pane, 1600, 900, Color.WHITESMOKE);
        primaryStage.setScene(scene);
        primaryStage.setTitle("Animation Player");
        
        primaryStage.show();
        
    }
    
    void loadAnimationFromFile(String fileName) {
        
    }
    
    void run() {
        
        launch();
    
    }
    
}
