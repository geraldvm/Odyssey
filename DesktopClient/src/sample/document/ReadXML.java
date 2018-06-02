package sample.document;

import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import sample.DataStructures.SimpleList;
import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;


public class ReadXML {
    private File xmlFile;
    public ReadXML(){
        xmlFile = new File(System.getProperty("user.home")+"/Music/Odyssey/temp/temp.xml");

    }
    public String getHead()throws Exception{
       return getHead_aux();
    }
    private String getHead_aux()throws Exception{

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();

       return e.getTagName();
    }

    public SimpleList<Message> sendMsg()throws Exception{
        return sendMsg_aux();
    }

    public SimpleList<String> userList()throws Exception{
        return userList_aux();
    }
    public SimpleList<String> songList()throws Exception{
        return songList_aux();
    }
    public boolean userVerification()throws Exception{
        return userVerification_aux();

    }public int songPost()throws Exception{
        return songPost_aux();
    }

    private SimpleList<Message> sendMsg_aux() throws Exception{

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();
        Node msg = e.getFirstChild();
        SimpleList<Message> msgList = new SimpleList<>();
        System.out.println(msg.compareDocumentPosition(e.getLastChild()));
        while (msg.compareDocumentPosition(e.getLastChild())!=330){
            if(msg.getNodeType()==Node.ELEMENT_NODE) {
                Element element = (Element) msg;
                Message m = new Message(element.getAttribute("Sender"),element.getAttribute("Song"));
                msgList.addLast(m);
            }msg=msg.getNextSibling();
        }
        Element element = (Element) msg;
        Message m = new Message(element.getAttribute("Sender"),element.getAttribute("Song"));
        msgList.addLast(m);
        return msgList;
    }
    private SimpleList<String> userList_aux() throws Exception{

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();
        Node users = e.getFirstChild();
        SimpleList<String> userList = new SimpleList<>();
        System.out.println(users.compareDocumentPosition(e.getLastChild()));
        while (users.compareDocumentPosition(e.getLastChild())!=330){
            if(users.getNodeType()==Node.ELEMENT_NODE) {
                Element element = (Element) users;
                String user = element.getAttribute("username");
                userList.addLast(user);
            }users= users.getNextSibling();
        }
        Element element = (Element) users;
        String user = element.getAttribute("username");
        userList.addLast(user);
        return userList;
    }
    private SimpleList<String> songList_aux()throws Exception{

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();
        Node song = e.getFirstChild();
        SimpleList<String> songList = new SimpleList<>();
        System.out.println(song.compareDocumentPosition(e.getLastChild()));
        while (song.compareDocumentPosition(e.getLastChild())!=330){
            if(song.getNodeType()==Node.ELEMENT_NODE) {
                Element element = (Element) song;
                String media = element.getAttribute("Song");
                songList.addLast(media);
            }song= song.getNextSibling();
        }
        Element element = (Element) song;
        String media = element.getAttribute("Song");
        songList.addLast(media);
        return songList;
    }
    private boolean userVerification_aux()throws Exception{
        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();
        Node user = e.getFirstChild();

        if(user.getNodeType()==Node.ELEMENT_NODE) {
            Element element = (Element) user;
            String status = element.getAttribute("Status");
            if (status == "Acepted") {
                return true;
            }
        }return false;
    }

    private int songPost_aux()throws Exception{
        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);
        Element e = document.getDocumentElement();
        Node song = e.getFirstChild();

        if(song.getNodeType()==Node.ELEMENT_NODE) {
            Element element = (Element) song;
            String size = element.getAttribute("Size");
            return Integer.parseInt(size);
        }return 0;
    }

}