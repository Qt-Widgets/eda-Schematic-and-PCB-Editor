const char *defaultSchematic = R"(
                           {
                                "schProperty":{},
                                "schPinLib":{},
                                "schPowerLib":{},
                                "schOffpageLib":{},
                                "schPartLib":{},
                                "pages":{}
                            }
                         )";

const char *defaultSchPage = R"(
                             {
                                  "pageProperty":{},
                                  "pageShape":[],
                                  "pagePart":[],
                                  "pageWire":[]
                              }

                             )";

const char *defaultSchProperty = R"(
                                 {
                                     "createdTime": 0,
                                     "modifiedTime": 0,
                                     "schematicName": "",
                                     "savePath": "H:/eda/eda/SchematicEditor/test/temp.json",
                                     "specVersion": 1.0
                                 }
                                 )";


const char *colorSchemeOrCAD =  R"(
                                   {
                                       "background":"#408080",
                                       "display":"#000000",
                                       "selection":"#FF00FF",
                                       "drawing":"#BF7F7F"
                                   }
                               )";

const char *colorSchemePads =  R"(
                                   {
                                       "background":"#408080",
                                       "display":"#000000",
                                       "selection":"#FF00FF",
                                       "drawing":"#BF7F7F"
                                   }
                               )";

const char *defaultPin = R"([
                         {
                             "pinLine": {
                                 "color": "#000000",
                                 "geometry": [
                                     [
                                         0.0,
                                         0.0
                                     ],
                                     [
                                         50.0,
                                         0.0
                                     ]
                                 ],
                                 "lineStyle": 1,
                                 "lineWidth": 0,
                                 "pos": [
                                     0.0,
                                     0.0
                                 ],
                                 "rotation": 0.0,
                                 "type": 100001
                             },
                             "pinName": {
                                 "pos": [
                                     -70.0,
                                     -6.0
                                 ],
                                 "text": "未命名管脚"
                             },
                             "pinNumber": {
                                 "number": 0,
                                 "pos": [
                                     0.0,
                                     0.0
                                 ]
                             },
                             "pinPort":{
                               "pos":[50,0],
                               "state":0
                             },
                             "pinShape": []
                         }
                        ])";
