class NoLista{
    constructor(valor, next){
        this.valor = valor;
        this.next = next;
    }
}

class ListaSimplesmenteEncadeada{
    constructor(){
        this.cuca = null;
        this.bunda = null;
    }

    addInicio(valor){
        let novoNo = new NoLista(valor, this.cuca);
        
        if(this.cuca == null){
            this.cuca = novoNo;
            this.bunda = novoNo;
        } else{
            this.cuca = novoNo;
        }        
    }

    addFim(valor){
        let novoNo = new NoLista(valor, null);

        if(this.cuca == null){
            this.cuca = novoNo;
            this.bunda = novoNo;
        } else {
            this.bunda.next = novoNo;
            this.bunda = novoNo;
        }
    }

    remove(valor){

        if(this.cuca == null){
            return;
        }

        if(this.cuca.valor == valor){
            
            this.cuca = this.cuca.next;

        } else {

            let noAtual = this.cuca;
            let noPorDeletar = null;

            while(noAtual.next != null){
                if(noAtual.next.valor == valor){
                    noPorDeletar = noAtual.next;
                    noAtual.next = noAtual.next.next;
                    break;
                }
                noAtual = noAtual.next;
            }

            if(noPorDeletar == null){
                console.log("Valor não encontrado");
            }

        }

    }

    ler(){
        if(this.cuca == null){
            console.log("Vazio");
            return;
        }
    
        let noAtual = this.cuca;

        console.log("Listando");
        while(noAtual != null){

            console.log(noAtual.valor);

            noAtual = noAtual.proximo;
        }
    }

}