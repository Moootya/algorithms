import httplib2
import apiclient
from oauth2client.service_account import ServiceAccountCredentials
from xlsxwriter.utility import xl_rowcol_to_cell


expenses = [
    ['=image("http://studenets.com/img/new/about.jpg?r={},j={}")'.format(j*i, j) for i in range(7000)]
    for j in range(1, 25)
]
print(len(expenses))

indexes = ['{}:{}'.format(
            xl_rowcol_to_cell(0, i),
            xl_rowcol_to_cell(10000, i + 1)
        ) for i in range(0, 50, 2)
]


print(len(indexes))
print()


body = {
    "valueInputOption": "USER_ENTERED",
    "data": [
        {
            "majorDimension": "COLUMNS",
            "range": indexes[i],
            "values": [expenses[i]]

        } for i in range(24)
    ]
}

# Файл, полученный в Google Developer Console
CREDENTIALS_FILE = 'creds.json'
# ID Google Sheets документа (можно взять из его URL)
spreadsheet_id = '1VLkliBc2Fi53hFLkDASSugtHPsbRLeJEKlORJ-ZzjcM'

# Авторизуемся и получаем service — экземпляр доступа к API
credentials = ServiceAccountCredentials.from_json_keyfile_name(
    CREDENTIALS_FILE,
    ['https://www.googleapis.com/auth/spreadsheets',
     'https://www.googleapis.com/auth/drive'])

httpAuth = credentials.authorize(httplib2.Http())
service = apiclient.discovery.build('sheets', 'v4', http = httpAuth)


# Пример записи в файл
values = service.spreadsheets().values().batchUpdate(
    spreadsheetId=spreadsheet_id,
    body=body
).execute()
