import org.w3c.dom.Document;
import org.w3c.dom.Element;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import java.io.File;

public class ReadXML {

    public static void main(String[] args) throws Exception{

        File xmlFile = new File("data.xml");

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();
        Document document = documentBuilder.parse(xmlFile);

        NodeList list = document.getElementsByTagName("Developer");

        for(int i =0;i<list.getLength();i++){
            Node node = list.item(i);

            if(node.getNodeType()==Node.ELEMENT_NODE){
                Element element=(Element) node;
                System.out.println("ID: "+element.getAttribute("ID"));
                System.out.println("Signal: "+element.getAttribute("Signal"));
                System.out.println("Name: "+element.getElementsByTagName("Name").item(0).getTextContent());
                System.out.println("Surname: "+element.getElementsByTagName("Surname").item(0).getTextContent());
                System.out.println("Age: "+element.getElementsByTagName("Age").item(0).getTextContent());
            }
        }
    }
}
