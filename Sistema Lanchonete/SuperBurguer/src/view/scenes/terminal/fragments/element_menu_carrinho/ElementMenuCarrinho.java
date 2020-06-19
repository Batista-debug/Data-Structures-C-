package view.scenes.terminal.fragments.element_menu_carrinho;

import java.io.IOException;

import database.models.Produto;
import javafx.fxml.FXMLLoader;
import javafx.scene.layout.Pane;
import view.util.DirectoryShortcuts;

public class ElementMenuCarrinho {

	public static Pane create(Produto produto, int qtd) {
		try {
			FXMLLoader loader = new FXMLLoader(DirectoryShortcuts.URL_ELEMENT_MENU_CARRINHO);
			
			ElementMenuCarrinhoController controller = new ElementMenuCarrinhoController(produto, qtd);
			loader.setController(controller);
			Pane pane = loader.load();
			return pane;
		} catch (IOException ex) {
			System.err.println("N�o foi poss�vel criar elemento do menu do carrinho.");
			ex.printStackTrace();
			return null;
		}
	}
	
}
