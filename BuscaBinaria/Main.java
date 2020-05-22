public class Main {
    public static void main(String args[])
    {
        ArvoreBuscaBinaria tree = new ArvoreBuscaBinaria();
 
        tree.insere(8);
        
        tree.remove(8);
        System.out.println("Imprimindo a arvore - Caso 1.1:");
        System.out.println(tree);
        
               
        tree.insere(8);
        tree.insere(3);
        tree.remove(8);
        System.out.println("Imprimindo a arvore - Caso 1.2:");
        System.out.println(tree);
        tree.remove(3);
        
        tree.insere(8);
        tree.insere(14);
        tree.remove(8);        
        System.out.println("Imprimindo a arvore - Caso 1.3:");
        System.out.println(tree);
        tree.remove(14);
        
        
        tree.insere(8);
        tree.insere(3);
        tree.insere(14);                
        tree.remove(8);        
        System.out.println("Imprimindo a arvore - Caso 1.4:");
        System.out.println(tree);
        tree.remove(14);
        tree.remove(3);
        
                
        tree.insere(8);
        tree.insere(3);
        tree.insere(10);                
        tree.insere(1);
        tree.insere(6);
        tree.insere(14);
        tree.insere(4);
        tree.insere(7);
        tree.insere(13);
        
        
        
        System.out.println("Imprimindo a arvore completa");
        System.out.println(tree);   

        
        tree.remove(4);
        System.out.println("Imprimindo a arvore - Caso 2");
        System.out.println(tree);
        
        tree.remove(6);
        System.out.println("Imprimindo a arvore - Caso 3.1");
        System.out.println(tree);
        
        tree.remove(14);
        System.out.println("Imprimindo a arvore - Caso 3.2");
        System.out.println(tree);
        
        tree.remove(3);
        System.out.println("Imprimindo a arvore - Caso 4");
        System.out.println(tree);
        
        tree.remove(8);
        System.out.println("Imprimindo a arvore");
        System.out.println(tree);
        
        tree.remove(1);
        System.out.println("Imprimindo a arvore");
        System.out.println(tree);
        
        tree.remove(7);
        System.out.println("Imprimindo a arvore");
        System.out.println(tree);
        
        tree.remove(10);
        System.out.println("Imprimindo a arvore");
        System.out.println(tree);
        
        tree.remove(13);
        System.out.println("Imprimindo a arvore");
        System.out.println(tree);
        
        tree.insere(8);
        tree.insere(3);
        tree.insere(10);                
        tree.insere(1);
        tree.insere(6);
        tree.insere(14);
        tree.insere(4);
        tree.insere(7);
        tree.insere(13);
        
        System.out.println("Imprimindo a arvore completa");
        System.out.println(tree);
        
        tree.remove(3);
        System.out.println("Imprimindo a arvore - Caso 4 (testando novamente, com arvore mais completa)");
        System.out.println(tree);       
    }
}