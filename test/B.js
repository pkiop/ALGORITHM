import React from 'react';
// import classnames from 'classnames';
// you should import `lodash` as a whole module
import lodash from 'lodash';
import axios from 'axios';

const ITEMS_API_URL = 'https://example.com/api/items';
const DEBOUNCE_DELAY = 500;

// the exported component can be either a function or a class

export default function Autocomplete(onSelectItem) {
  let items = [];

  const inputControlRef = React.useRef(null);
  const inputValueRef = React.useRef(null);

  const getItems = lodash.debounce(() => {
    if(inputControlRef) {
      inputControlRef.current.classList.add('is-loading');
    }    

    axios.get(ITEMS_API_URL + `/q=${inputValueRef.current.value}`).then((fetchItems) => {
      items = fetchItems.map((fetchItem) => {
        return (<a className="list-item" onClick={() => onSelectItem(fetchItem)}>{fetchItem}</a>);
      });
      inputControlRef.current.classList.remove('is-loading');
    }).catch((error) => {
      inputControlRef.current.classList.remove('is-loading');
      console.error("ERROR : ", error);
    });
  }, DEBOUNCE_DELAY);

  function inputOnChange() {
    getItems();
  }

  return (
    <div className="wrapper">
      <div ref={inputControlRef} className="control">
        <input ref={inputValueRef} onChange={inputOnChange} type="text" className="input" />
      </div>
      <div className="list is-hoverable" />
      <div className="list">
        {items}
      </div>
    </div>
  );
}
