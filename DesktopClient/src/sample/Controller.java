package sample;

import com.jfoenix.controls.JFXComboBox;
import com.jfoenix.controls.JFXRadioButton;
import com.jfoenix.controls.JFXTextField;
import javafx.application.Platform;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;

import javafx.scene.control.Alert;
import javafx.scene.control.ToggleGroup;
import javafx.scene.image.ImageView;
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;

import java.net.URL;
import java.util.ResourceBundle;

public class Controller implements Initializable{
    @FXML private ImageView userArrow, playerArrow, libraryArrow,socialArrow;
    @FXML private ImageView playerBtn,libraryBtn,socialBtn;
    @FXML private AnchorPane loginPanel,logoutPanel,userPanel, playerPanel, libraryPanel, socialPanel;
    @FXML private JFXComboBox<String> comboBoxGenre;
    @FXML private JFXRadioButton okRadioButton,noRadioButton;
    @FXML private JFXTextField nameText,lastnameText,usernameText,passwordText,ageText;
    @FXML private JFXTextField userLogText,passwordLogText;
    private int sessionPanel;

    ObservableList<String> comboGenreContent =
            FXCollections.observableArrayList(
                    "Pop","Rock","Reggae","R&B",
                    "Hip-Hop","Dance-Hall","House"
            );

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {//"Constructor" de las variables de la interfaz
        nameText.addEventFilter(KeyEvent.ANY, handlerLetters);
        lastnameText.addEventFilter(KeyEvent.ANY, handlerLetters);
        ageText.addEventFilter(KeyEvent.ANY,handlerNumbers);

        comboBoxGenre.setItems(comboGenreContent);

        sessionPanel = 0;

        playerBtn.setDisable(true);
        libraryBtn.setDisable(true);
        socialBtn.setDisable(true);

        ToggleGroup group = new ToggleGroup();
        okRadioButton.setToggleGroup(group);
        noRadioButton.setToggleGroup(group);
    }



    public void onExitButtonClicked(MouseEvent event){
        Platform.exit();
        System.exit(0);

    }
    public void onUserButtonClicked(MouseEvent event){
        if(logoutPanel.isVisible()&&sessionPanel==1){
            userArrow.setVisible(false);
            logoutPanel.setVisible(false);

        }else if(sessionPanel==0){
            userPanel.setVisible(false);
            loginPanel.setVisible(true);
            userArrow.setVisible(true);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(false);
            socialPanel.setVisible(false);

        }
        else if((!logoutPanel.isVisible())&&sessionPanel==1){
            userArrow.setVisible(true);
            logoutPanel.setVisible(true);
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
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
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
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
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
            loginPanel.setVisible(false);
            logoutPanel.setVisible(false);
            playerArrow.setVisible(false);
            playerPanel.setVisible(false);
            libraryArrow.setVisible(false);
            libraryPanel.setVisible(false);
            socialArrow.setVisible(true);
            socialPanel.setVisible(true);
        }

    }

    EventHandler<KeyEvent> handlerLetters = new EventHandler<KeyEvent>() {
        private boolean willConsume = false;
        @Override
        public void handle(KeyEvent event) {
            Object tempO = event.getSource();
            if(willConsume){
                event.consume();
            }String temp = event.getCode().toString();
            //If toma lo que se teclea  Compara si es minucula o mayusculas, si no es espacio entonces no muestra nada
            if(!event.getCode().toString().matches("[a-zA-Z]")&&event.getCode()!= KeyCode.BACK_SPACE
                    && event.getCode()!=KeyCode.SHIFT){
                if(event.getEventType()==KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }

        }
    };

    EventHandler<KeyEvent> handlerNumbers = new EventHandler<KeyEvent>() {
        private boolean willConsume = false;
        private int maxLength = 2;

        @Override
        public void handle(KeyEvent event) {
            JFXTextField temp = (JFXTextField) event.getSource();

            if(willConsume){
                event.consume();
            }
            if(!event.getText().matches("[0-9]")&& event.getCode()!=KeyCode.BACK_SPACE){
                if(event.getEventType() == KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }
            if(temp.getText().length()>maxLength-1){
                if(event.getEventType()==KeyEvent.KEY_PRESSED){
                    willConsume=true;
                }else if(event.getEventType()==KeyEvent.KEY_RELEASED){
                    willConsume=false;
                }
            }

        }
    };

    public void onComboGenreChanged(ActionEvent event){


        if(comboBoxGenre.getValue().equals("Hip-Hop")){
                nameText.setDisable(true);


        }

    }
    public void onSaveButton(ActionEvent event){
        if(nameText.getText().isEmpty()||usernameText.getText().isEmpty()||
                lastnameText.getText().isEmpty()||ageText.getText().isEmpty()||
                passwordText.getText().isEmpty()){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Save Profile");
            alert.setContentText("Please, fill out the entire blank");
            alert.show();
        }
        System.out.println(usernameText.getText().toString());
        System.out.println(nameText.getText());
        System.out.println(lastnameText.getText());
        System.out.println(ageText.getText());
        System.out.println(passwordText.getText());
        playerBtn.setDisable(false);
        libraryBtn.setDisable(false);
        socialBtn.setDisable(false);
        userPanel.setVisible(false);
        logoutPanel.setVisible(true);
        sessionPanel=1;

    }

    public void onLoginButton(ActionEvent event){
        if(userLogText.getText().isEmpty()||passwordLogText.getText().isEmpty()){
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Login");
            alert.setContentText("Please, fill out the entire blank");
            alert.show();
        }
        System.out.println(userLogText.getText().toString());
        System.out.println(passwordLogText.getText());
        playerBtn.setDisable(false);
        libraryBtn.setDisable(false);
        socialBtn.setDisable(false);
        loginPanel.setVisible(false);
        loginPanel.setVisible(false);
        logoutPanel.setVisible(true);
        sessionPanel=1;
        //Abrir ventana cerrar sesion
    }
    public void onRegisterButton(ActionEvent event){
        loginPanel.setVisible(false);
        userPanel.setVisible(true);

    }
    public void onLogoutButton(ActionEvent event){
        loginPanel.setVisible(true);
        userPanel.setVisible(false);
        logoutPanel.setVisible(false);
        playerBtn.setDisable(true);
        libraryBtn.setDisable(true);
        socialBtn.setDisable(true);
        sessionPanel=0;
    }



}
