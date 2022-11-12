package finalproject;

public class FinalProject {

    public static void main(String[] args) {
        
        AnimationPlayer player = new AnimationPlayer();
        player.loadAnimationFromFile("animation.txt");
        player.run();
        
    }
    
}
