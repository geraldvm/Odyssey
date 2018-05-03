package sample;

import javafx.application.Platform;
import javafx.beans.Observable;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.ComboBox;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;

import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable{
    @FXML private ImageView userArrow, playerArrow, libraryArrow,socialArrow;
    @FXML private AnchorPane userPanel, playerPanel, libraryPanel, socialPanel;
    @FXML private ComboBox<Integer> comboBoxAge;
    @FXML private ComboBox<String> comboBoxGenre;
    ObservableList<Integer> comboAgeContent =
            FXCollections.observableArrayList(
                    10,11,12,15,45,55,25,2,98,62,26,4,6,54,82
            );

    ObservableList<String> comboGenreContent =
            FXCollections.observableArrayList(
                    "Pop","Rock","Reggae","R&B",
                    "Hip-Hop","Dance-Hall","House"
            );

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {//"Constructor" de las variables de la interfaz
        comboBoxAge.setItems(comboAgeContent);
        comboBoxGenre.setItems(comboGenreContent);
    }



    public void onExitButtonClicked(MouseEvent event){
        Platform.exit();
        System.exit(0);

    }
    public void onUserButtonClicked(MouseEvent event){
        if(userPanel.isVisible()){
            userArrow.setVisible(false);
            userPanel.setVisible(false);
        }else {
            userArrow.setVisible(true);
            userPanel.setVisible(true);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }

    }
    public void onPlayerButtonClicked(MouseEvent event){
        if(playerPanel.isVisible()){
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
        }else {
            userArrow.setVisible(false);
            userPanel.setVisible(false);
            playerArrow.setVisible(true);
            playerPanel.setVisible(true);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }

    }
    public void onLibraryButtonClicked(MouseEvent event){
        if(libraryPanel.isVisible()){
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
        }else {
            userArrow.setVisible(false);
            userPanel.setVisible(false);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(true);
            libraryPanel.setVisible(true);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }

    }
    public void onSocialButtonClicked(MouseEvent event){
        if(socialPanel.isVisible()){
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);
        }else {
            userArrow.setVisible(false);
            userPanel.setVisible(false);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(true);
            socialPanel.setVisible(true);
        }

    }


}
