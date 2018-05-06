package sample;

import javafx.application.Application;
import javafx.event.EventHandler;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.input.MouseEvent;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;

public class Main extends Application {
    private double yOffset;
    private  double xOffset;
    @Override
    public void start(Stage primaryStage) throws Exception{

        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        /**
         * Methods to move window
         */
        root.setOnMousePressed(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                yOffset= event.getSceneY();
                xOffset= event.getSceneX();
            }
        });
        root.setOnMouseDragged(new EventHandler<MouseEvent>() {
            @Override
            public void handle(MouseEvent event) {
                primaryStage.setX(event.getScreenX() - xOffset);
                primaryStage.setY(event.getScreenY() - yOffset);

            }
        });


        primaryStage.setTitle("Odyssey Desktop App");
        primaryStage.initStyle(StageStyle.TRANSPARENT);
        Scene scene = new Scene(root);//new Scene(root, 300, 275) size
        scene.setFill(Color.TRANSPARENT);
        primaryStage.setScene(scene);//new Scene(root, 300, 275) size
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}