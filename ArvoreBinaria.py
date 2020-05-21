class _No:

    def __init__(self, chave, valor, esquerda = None, direita = None):
        self.valor = valor
        self.chave = chave 
        self.fe = esquerda
        self.fd = direita

        def __str__(self):
            return "{}:{}".format(self.chave.__repr__(), self.valor.__repr__())

            class Arvore:

                def __init__(self, iteravel = None):
                    self.raiz = None
                    if not iteravel is None:
                        for chave, valor in iteravel:
                            self.inserir(chave, valor)



        def inserir(self, chave, valor):
            
            self.raiz = self. __inserir(self.raiz, chave, valor)


        def __inserir(self, no, valor):

            if no is None:
                return _No(chave, valor)
            elif chave > no.chave:
                no.fd = self.__inserir(no.fd, chave, valor)
            elif chave < no.chave:
                no.fe = self.__inserir(no.fe, chave, valor)
            else:
                no.valor = valor

            return no


    def buscar(self, chave):

        no = self.raiz
        while no is not None:
            if chave == no.chave:
                return no.valor 
                elif chave < no.chave
                no = no.fe
                else 
                no = no.fd

                raise KeyError (chave)

def remover(self, chave):


    self.raiz, valor = self __remover(self.raiz, chave)
    return valor 

def __remover(self, nodo, chave):
    if nodo is None:
        raise KeyError(chave)
    elif chave > nodo.chave:
        nodo.fd, valor = self.__remove(nodo.fd, chave)
        elif chave < nodo.chave:
            no = no.fe
        else:
            no = no.fd
    raise KeyError (chave)

def remover(self,chave):


    self.raiz, valor = self.__remover(self.raiz, chave)
    return valor


def __remover(self, nodo, chave):
    is nodo is None
        raise KeyError(chave)
    elif chave > nodo.chave:
        nodo.fd, valor = self.__remover(nodo.fd, chave)
    elif chave < nodo.chave:
        nodo.fe, valor = self.__remover(nodo.fe, chave)
    else:
        valor = nodo.valor
        if nodo.fd is None:
            aux = nodo
            nodo = nodo.fe
            del aux

        else:
            nodo.fd = self.__sucessor(nodo, nodo.fd)
        return nodo, valor

        def __sucessor(self, no, nodo):

            if nodo.fe is not None:
                nodo.fe = self.__sucessor(no, nodo.fe)            
            else:
                aux = nodo
                no.valor = nodo.valor
                no.chave = nodo.chave
                nodo = nodo.fd
                del aux
                return nodo

                def __contar(self, n)


                    if not n is None:
                        return self.__contar(n.fe)+self.__contar(.fd)+1
                        else:
                            return 0

        def em_ordem(self, nodo):

            msg =''
            if nodo is not None:

                aux = self.em_ordem(nodo.fe)
                msg += aux
                if aux: msg += ', '
                msg += str(nodo)


                aux = self.em_ordem(nodo.fd)
                if aux: msg += ', '
                msg += aux

                return msg        