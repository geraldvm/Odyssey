public class main {
    public static void main(String[] args){
        algoGenetico genetico = new algoGenetico("en Real definicion","en la definición en el diccionario de la Real Academia Española se encuentra que tecnología es el conjunto de teorías y técnicas estas son usadas para aprovechar el conocimiento científico Por otro lado también indica que es un conjunto de procedimientos e instrumentos industriales de un sector o producto en lo referente a que algo sea tecnológico se le encuentra como característica a un objeto según el sitio web de diccionario de Oxford algo tecnológico es algo si está relacionado con la tecnología la definición anterior es muy similar a la propuesta por la RAE que indica tecnológico como perteneciente o relativo a la tecnología los residuos sólidos se refieren a los objetos que son descartados al igual que como lo indica el sitio web Definición que indica un desecho sólido como algo descartado y que no posee ningún valor económico\n");
        String[] palabras = genetico.generarHijos();
        for (int i = 0; i < palabras.length; i++) {
            System.out.print(palabras[i]+" ");
        }
        System.out.print('\n');
        genetico.aumentarGeneraciones();
        palabras = genetico.generarHijos();
        for (int i = 0; i < palabras.length; i++) {
            System.out.print(palabras[i]+" ");
        }
        System.out.print('\n');
        genetico.aumentarGeneraciones();
        palabras = genetico.generarHijos();
        for (int i = 0; i < palabras.length; i++) {
            System.out.print(palabras[i]+" ");
        }
        System.out.print('\n');
    }
}
