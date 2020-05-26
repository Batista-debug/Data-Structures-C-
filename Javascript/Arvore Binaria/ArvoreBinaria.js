class No{
    constructor(valor, fe, fd){
        this.valor = valor;
        this.fe = fe;
        this.fd = fd;
    }
}

class ArvoreDeBuscaBinaria{
    constructor(){
        this.raiz = null;
    }

    add(valor){
        let novoNo = new No(valor, null, null);

        if(this.raiz == null)
            this.raiz = novoNo;

        else {
            let auxiliar = this.raiz;
            let encontrado = false;

            while(!encontrado){
                if(novoNo.valor < auxiliar.valor){
                    if(auxiliar.fe == null){
                        auxiliar.fe = novoNo;
                        encontrado = true;
                    } else {
                        auxiliar = auxiliar.fe;
                    }

                } else {
                    if(auxiliar.fd == null){
                        auxiliar.fd = novoNo;
                        encontrado = true;
                    } else {
                        auxiliar = auxiliar.fd;
                    }
                }
            }
        }
    }

    remove(valor){
        let auxiliar = this.raiz
        let encontrado = false;

        if(valor != this.raiz.valor){
            let anterior = this.raiz;

            while(auxiliar != null && !encontrado){
                if(valor == auxiliar.valor){
                    encontrado = true;
                } else if(valor < auxiliar.valor){
                    anterior = auxiliar;
                    auxiliar = auxiliar.fe;
                } else {
                    anterior = auxiliar;
                    auxiliar = auxiliar.fd;
                }
            }

            if(auxiliar == null){
                console.log("Elemento não existe");
                return;
            }

            if(auxiliar.fd == null && auxiliar.fe == null){
                if(anterior.fe == auxiliar) anterior.fe = null;
                else anterior.fd = null;
                
            } else if(auxiliar.fd != null && auxiliar.fe == null){
                if(anterior.fe == auxiliar) anterior.fe = auxiliar.fd;
                else anterior.fd = auxiliar.fd;

            } else if(auxiliar.fd == null && auxiliar.fe!= null){
                if(anterior.fe == auxiliar) anterior.fe = auxiliar.fe;
                else anterior.fd = auxiliar.fe;

            } else {
                let noDireitaElementoEscluido = auxiliar.fd;
                let noEsquerdaElementoEscluido = auxiliar.fe;
                let anteriorDoAuxiliar;

                if(auxiliar == anterior.fd){
                    auxiliar = auxiliar.fe;
                    while(auxiliar.fd != null){
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.fd;
                    }
                    anterior.fd = auxiliar;

                } else {
                    auxiliar = auxiliar.fe;
                    while(auxiliar.fd != null){
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.fd;
                    }
                    anterior.fe = auxiliar;

                }

                auxiliar.fd = noDireitaElementoEscluido;
                auxiliar.fe = noEsquerdaElementoEscluido;
                anteriorDoAuxiliar.fd = null;
            }

        } else {
            if(auxiliar.fd == null && auxiliar.fe == null) {
                this.raiz = null;
            } else {
                if (auxiliar.fe != null && auxiliar.fd == null) 
                    this.raiz = auxiliar.fe;
                else if (auxiliar.fe == null && auxiliar.fd != null)
                    this.raiz = auxiliar.fd;
                else if (auxiliar.fe != null && auxiliar.fd != null) {
                    let noDireitaElementoEscluido = this.raiz.fd;
                    let noEsquerdaElementoEscluido = this.raiz.fe;
                    let anteriorDoAuxiliar;
                        
                    auxiliar = this.raiz.fe;
                    while(auxiliar.fd != null) {	
                        anteriorDoAuxiliar = auxiliar;
                        auxiliar = auxiliar.fd;
                    }
                    this.raiz = auxiliar;
                        
                    auxiliar.fd = noDireitaElementoEscluido;
                    auxiliar.fe = noEsquerdaElementoEscluido;
                    anteriorDoAuxiliar.fd = null;
                }
            }

        }
    }

    verificaElemento(valor){
        let auxiliar = this.raiz;
        encontrado = false;

        while(auxiliar != null && !encontrado){
            if(valor == auxiliar.valor) encontrado = true; 
            else if (valor < auxiliar.valor) auxiliar = auxiliar.fe;
            else if (valor > auxiliar.valor) auxiliar = auxiliar.fd;
        }

        if(encontrado) console.log("Elemento Presente");
        else console.log("Elemento Não Encontrado");
    }

    consultaPreOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        console.log(auxiliar.valor);
        if(auxiliar.fe != null) this.consultaPreOrdem(auxiliar.fe);
        if(auxiliar.fd != null) this.consultaPreOrdem(auxiliar.fd);
    }

    consultaPosOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        if(auxiliar.fe != null) this.consultaPosOrdem(auxiliar.fe);
        if(auxiliar.fd != null) this.consultaPosOrdem(auxiliar.fd);
        console.log(auxiliar.valor);
    }
    
    consultaOrdem(raiz = this.raiz){
        let auxiliar = raiz;

        if(auxiliar.fe != null) this.consultaOrdem(auxiliar.fe);
        console.log(auxiliar.valor);
        if(auxiliar.fd != null) this.consultaOrdem(auxiliar.fd);
    }

    esvaziar(){
        this.raiz = null;
    }
}