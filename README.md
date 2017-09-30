libautomata Version beta (C) Copyright 2017 by Takashi Tanaka

１．はじめに
　これはC言語のプログラム中にて，
ユーザ自身が定義した任意のオートマトンを実行するためのライブラリの開発版です．

	このバージョンでサポートされるオートマトンは，
		・決定性有限オートマトン（DFA）
		・非決定性有限オートマトン（NFA）
		・空動作を含む非決定性有限オートマトン（ε-NFA）
	となっております．
２．概要　
　バージョン0.0.1ではプログラム上にて定義されたAUTOMATA構造体に対するアクセスによって，
ライブラリ関数を利用していたところをint型のディスクリプタを介して利用できるように変更．
　
　データ構造を見直し一新した．

　ライブラリ関数の仕様を一新した．
　
３．著作権 (C) Copyright 2017 by Takashi Tanaka

４．作者 Takashi　Tanaka 連絡先: isazaka@gmail.com

５．配布条件 このソフトウェアによって利用者または第三者が何らかの被害を受けた場合， 作者はその責任を一切負いません． また，このソフトウェアはGNU GPLv3をライセンスとして含みます． 詳しい条文については同梱のCOPYINGを参照して下さい． これらの条件を承諾する限りにおいて，利用・改変・配布することが可能です．

必ずGNU GPLライセンスに関するWebページをご覧になって下さい． https://www.gnu.org/licenses/
