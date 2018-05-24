package sample.client;


import sample.DataStructures.SimpleList;
import sample.document.Message;
import sample.document.ReadXML;

public class Logic {
    private ReadXML xml;

    public Logic(){
        xml = new ReadXML();


    }
    public void decision()throws Exception{
        decision_aux();
    }
    private void decision_aux()throws Exception{
        String option= xml.getHead();
        if(option=="userVerification"){
            if(xml.userVerification()){
                System.out.println("PROFILE ACCEPTED");
            }
        }else if(option=="UserList"){
            SimpleList<String> users = xml.userList();
        }else if(option=="SongList"){
            SimpleList<String> songs = xml.songList();
        }else if(option=="msgList"){
            SimpleList<Message> msgs = xml.sendMsg();
        }else if(option=="SongPost"){
            int songSize= xml.songPost();
        }
    }
}
