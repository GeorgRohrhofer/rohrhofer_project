%% htldipl.cls
%% Modifiziert von: Wolfgang Schermann
%% Ursprünglich: hgbthesis.cls
%% Ursprünglicher Autor: Wilhelm Burger (wilhelm.burger@fh-hagenberg.at)

\NeedsTeXFormat{LaTeX2e}
\newcommand{\htldiplDate}{2018/07/01} %Versionsdatum
\ProvidesClass{htldipl}[\htldiplDate\space LaTeX-Vorlage fuer Diplomarbeiten
der HTL Wiener Neustadt]

\author{ }

\RequirePackage{ifthen}
\RequirePackage{pdfpages}

\newcommand{\htl@MainLanguage}{german}	% also referenced in htl.sty
\newcommand{\htl@DoubleSided}{oneside}
\newcommand{\htl@Colorcode}{color}
\newcommand{\@datitelseiten}{}
\newcommand{\@maketitlepages}{\@datitelseiten}  %default: Diplomarbeit


%% begin class options ---------------------------------------------
\DeclareOption{diplom}{\renewcommand{\@maketitlepages}{\@datitelseiten}}
\DeclareOption{english}{\renewcommand{\htl@MainLanguage}{english}}
\DeclareOption{german}{\renewcommand{\htl@MainLanguage}{german}}
\DeclareOption{oneside}{\renewcommand{\htl@DoubleSided}{oneside}}
\DeclareOption{twoside}{\renewcommand{\htl@DoubleSided}{twoside}}
\DeclareOption{color}{\renewcommand{\htl@Colorcode}{color}}
\DeclareOption{black}{\renewcommand{\htl@Colorcode}{black}}
\DeclareOption*{\ClassWarning{htldipl}{Unknown document option
"\CurrentOption"}}
\ProcessOptions
%% end class options ---------------------------------------------
 
\ifthenelse{\equal{\htl@DoubleSided}{oneside}}%
	{\LoadClass[a4paper,11pt,oneside]{book} }{}
\ifthenelse{\equal{\htl@DoubleSided}{twoside}}%
	{\LoadClass[a4paper,11pt,twoside]{book}%
	 \RequirePackage{emptypage}}{}

 
\RequirePackage{htl}[2015/07/09]	% load associated style file htl.sty

\RequirePackage[toc]{glossaries}

%-------------- Setup für Seiten im Front-Teil --------------------

\newcommand{\@abteilung}{\@MissingArg{Abteilung??}}
\newcommand{\abteilung}[1]{%
	\renewcommand{\@abteilung}{#1}
}

\newcommand{\@schwerpunkt}{\@MissingArg{Schwerpunkt??}}
\newcommand{\schwerpunkt}[1]{%
	\renewcommand{\@schwerpunkt}{#1}
}

\newcommand{\@studienort}{\@MissingArg{Studienort??}}
\newcommand{\studienort}[1]{%
	\renewcommand{\@studienort}{#1}
}

\newcommand{\@betreuerA}{\@MissingArg{BetreuerA??}}
\newcommand{\betreuerA}[1]{%
	\renewcommand{\@betreuerA}{#1}
}

\newcommand{\@betreuerB}{\@MissingArg{BetreuerB??}}
\newcommand{\betreuerB}[1]{%
	\renewcommand{\@betreuerB}{#1}
}

\newcommand{\@betreuerC}{\@MissingArg{BetreuerC??}}
\newcommand{\betreuerC}[1]{%
	\renewcommand{\@betreuerC}{#1}
}

\newcommand{\@betreuerD}{\@MissingArg{BetreuerD??}}
\newcommand{\betreuerD}[1]{%
	\renewcommand{\@betreuerD}{#1}
}

\newcommand{\@gegenstand}{\@MissingArg{Gegenstand??}}
\newcommand{\gegenstand}[1]{%
	\renewcommand{\@gegenstand}{#1}
}

\newcommand{\@abgabejahr}{\@MissingArg{Jahr??}}
\newcommand{\abgabejahr}[1]{%
	\renewcommand{\@abgabejahr}{#1}
} 

\newcommand{\@schule}{\@MissingArg{Schule??}}
\newcommand{\schule}[1]{%
	\renewcommand{\@schule}{#1}
}

\newcommand{\@schullogo}{\@MissingArg{Schullogo??}}
\newcommand{\schullogo}[1]{%
	\renewcommand{\@schullogo}{#1}
}

\newcommand{\@schuelerA}{\@MissingArg{SchuelerA??}}
\newcommand{\schuelerA}[1]{%
	\renewcommand{\@schuelerA}{#1}
}

\newcommand{\@schuelerB}{\@MissingArg{SchuelerB??}}
\newcommand{\schuelerB}[1]{%
	\renewcommand{\@schuelerB}{#1}
}

\newcommand{\@schuelerC}{\@MissingArg{SchuelerC??}}
\newcommand{\schuelerC}[1]{%
	\renewcommand{\@schuelerC}{#1}
}

\newcommand{\@schuelerD}{\@MissingArg{SchuelerD??}}
\newcommand{\schuelerD}[1]{%
	\renewcommand{\@schuelerD}{#1}
}

\newcommand{\@schuelerE}{\@MissingArg{SchuelerE??}}
\newcommand{\schuelerE}[1]{%
	\renewcommand{\@schuelerE}{#1}
}


\newcommand{\@evidenzA}{\@MissingArg{EvidenzA??}}
\newcommand{\evidenzA}[1]{%
	\renewcommand{\@evidenzA}{#1}
}

\newcommand{\@evidenzB}{\@MissingArg{EvidenzB??}}
\newcommand{\evidenzB}[1]{%
	\renewcommand{\@evidenzB}{#1}
}

\newcommand{\@evidenzC}{\@MissingArg{EvidenzC??}}
\newcommand{\evidenzC}[1]{%
	\renewcommand{\@evidenzC}{#1}
}

\newcommand{\@evidenzD}{\@MissingArg{EvidenzD??}}
\newcommand{\evidenzD}[1]{%
	\renewcommand{\@evidenzD}{#1}
}

\newcommand{\@evidenzE}{\@MissingArg{EvidenzE??}}
\newcommand{\evidenzE}[1]{%
	\renewcommand{\@evidenzE}{#1}
}



\newcommand{\@subthemaA}{\@MissingArg{SubthemaA??}}
\newcommand{\subthemaA}[1]{%
	\renewcommand{\@subthemaA}{#1}
}

\newcommand{\@subthemaB}{\@MissingArg{SubthemaB??}}
\newcommand{\subthemaB}[1]{%
	\renewcommand{\@subthemaB}{#1}
}

\newcommand{\@subthemaC}{\@MissingArg{SubthemaC??}}
\newcommand{\subthemaC}[1]{%
	\renewcommand{\@subthemaC}{#1}
}

\newcommand{\@subthemaD}{\@MissingArg{SubthemaD??}}
\newcommand{\subthemaD}[1]{%
	\renewcommand{\@subthemaD}{#1}
}

\newcommand{\@subthemaE}{\@MissingArg{SubthemaE??}}
\newcommand{\subthemaE}[1]{%
	\renewcommand{\@subthemaE}{#1}
}

%------------------ Titelseite -------------------


%% Headings -------------------------------------------------------------

\RequirePackage{fancyhdr}
\pagestyle{fancy}

\@ifundefined{chapter}%
   {}%
	 {\renewcommand{\chaptermark}[1]{%
			\ifthenelse{\value{chapter} < 1}%
				{\markboth{#1}{}}%
				{\markboth{\thechapter.\ #1}{}}
		}}

\addtolength{\headheight}{\baselineskip}
\renewcommand{\headrulewidth}{0pt} %% thin line under header
%\renewcommand{\headrulewidth}{0.4pt} %% no line under header
\renewcommand{\footrulewidth}{0pt}
\fancyhf{}                            %% Clear all fields.
%\fancyhead[LE,RO]{\sffamily\thepage} %{\bf \rightmark}
%\fancyhead[LO,RE]{\sffamily\nouppercase{\leftmark}}  %{\slshape \leftmark}
\fancyhead[R]{\sffamily\thepage} %{\bf \rightmark}
\fancyhead[L]{\sffamily\nouppercase{\leftmark}}  %{\slshape \leftmark}

\fancypagestyle{plain}{%
	\fancyhf{} % clear all header and footer fields
	\fancyfoot[C]{\sffamily\thepage} % except the center
	\renewcommand{\headrulewidth}{0pt}
	\renewcommand{\footrulewidth}{0pt}
}



%%-------------------------------------------------------------



\endinput

