
package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.paint.Color;
import javafx.stage.Stage;
import javafx.stage.StageStyle;
import sample.DataStructures.SimpleList;
import sample.document.XMLDocument;

import java.io.File;

public class Main extends Application {
    private double yOffset;
    private  double xOffset;
    @Override
    public void start(Stage primaryStage) throws Exception{
        /*
        XMLDocument xml = new XMLDocument();

        xml.modifySong(1,1,"ltitle","cancion","artista","album","2016","laletra","genero","3");
        */
        try {
            File f = new File("/home/gerald/Music/Library");

            if (f.isFile()) {
                System.out.println(f.getName());

                //send File
            } else {
                File[] listOfFiles = f.listFiles();
                for (File file : listOfFiles) {
                    if (file.isFile()) {
                        //send path+"/"+file.getName();
                        //System.out.println(file.getName().contains("mp4"));
                        if(f.getName().contains("mp4")) {
                            System.out.println(file.getName());
                        }
                    }

                }
            }
        }catch (Exception j){};

        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        root.setOnMousePressed(event -> {
            yOffset= event.getSceneY();
            xOffset= event.getSceneX();
        });
        root.setOnMouseDragged(event -> {
            primaryStage.setX(event.getScreenX() - xOffset);
            primaryStage.setY(event.getScreenY() - yOffset);

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
