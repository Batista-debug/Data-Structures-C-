public class No{

    private int valor;
    private No dir;
    private No esq;

    public int getValor(){
        return valor;
    }

    public void setValor(int valor){
        this.valor = valor;
    }

    public No getDireita(){
        return dir;
    }

    public void setDireita(No dir){
        this.dir = dir;
    }

    public No getEsquerda(){
        return esq;
    }

    public void setEsquerda(int esq){
        this.esq = esq;
    }

    public No(int valor, No dir, No esq){
        this.valor = valor;
        this.dir = dir;
        this.esq = esq;
    }

    @Override
    public String toString() {
        return Integer.toString(this.getValor()); 
    }
    
    public No sucessor(No no)
    {
        No sucessor = no;
        
        sucessor = sucessor.getDireita();
        
        while(sucessor.getEsquerda() != null)
            sucessor = sucessor.getEsquerda();
        
        return sucessor;
    }
    
    public No antecessor(No no)
    {
        No antecessor = no;
        
        antecessor = antecessor.getEsquerda();
        
        while(antecessor.getDireita() != null)
        {
            antecessor = antecessor.getDireita();
        }
        
        return antecessor;
    }
   
    
}

