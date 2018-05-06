import org.w3c.dom.Attr;
import org.w3c.dom.Document;
import org.w3c.dom.Element;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.transform.Transformer;
import javax.xml.transform.TransformerFactory;
import javax.xml.transform.dom.DOMSource;
import javax.xml.transform.stream.StreamResult;
import java.io.File;

public class CreateXML {

    public static void main(String[] args) throws Exception{

        DocumentBuilderFactory documentBuilderFactory = DocumentBuilderFactory.newInstance();
        DocumentBuilder documentBuilder = documentBuilderFactory.newDocumentBuilder();

        Document document = documentBuilder.newDocument();

        Element element = document.createElement("Developer");
        document.appendChild(element);

        Attr attr = document.createAttribute("ID");
        attr.setValue("1");
        element.setAttributeNode(attr);
        attr = document.createAttribute("Signal");
        attr.setValue("5550");
        element.setAttributeNode(attr);

        Element name = document.createElement("Name");
        name.appendChild(document.createTextNode("Gerald"));
        element.appendChild(name);


        Element surname = document.createElement("Surname");
        surname.appendChild(document.createTextNode("Valverde"));
        element.appendChild(surname);

        Element age = document.createElement("Age");
        age.appendChild(document.createTextNode("20"));
        element.appendChild(age);

        TransformerFactory transformerFactory = TransformerFactory.newInstance();
        Transformer transformer = transformerFactory.newTransformer();
        DOMSource source = new DOMSource(document);

        StreamResult streamResult = new StreamResult(new File("data.xml"));

        transformer.transform(source,streamResult);




    }
}
