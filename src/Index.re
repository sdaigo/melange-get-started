module App = {
  [@react.component]
  let make = () =>
    <div>
      <Counter /> //
      <CelsiusConverter />
    </div>;
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
